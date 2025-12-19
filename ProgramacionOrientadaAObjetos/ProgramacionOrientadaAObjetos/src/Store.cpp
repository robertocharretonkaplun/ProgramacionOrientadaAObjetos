#include "PuntoDeVenta\Store.h"

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
  ProductDTO,
  id,
  name,
  price,
  stock,
  type,
  expirationDate
)


bool 
Store::LoadInventory(const std::string& filePath) {
	std::ifstream file(filePath);

	if (!file.is_open()) {
		std::cout << "No se pudo abrir " << filePath << "\n";
		return false;
	}

	json j;
	file >> j;

	m_products.clear();

  for (const auto& p : j["products"]) {
    ProductDTO dto = p.get<ProductDTO>();

    auto prod = std::make_unique<Product>(
      dto.id,
      dto.name,
      dto.price,
      dto.stock,
      dto.type,
      dto.expirationDate
    );

    m_products.push_back(std::move(prod));
  }

  std::cout << "Inventario cargado: "
    << m_products.size() << " productos.\n";

  return true;
}

void 
Store::ShowInventory() const {
  std::cout << "\n=== INVENTARIO ===\n";
  for (const auto& up : m_products) {   // up = unique_ptr<Product>
    const Product& p = *up;          // referencia al objeto

    std::cout << p.GetId() << " - " << p.GetName()
      << " | $" << p.GetPrice()
      << " | stock: " << p.GetStock()
      << " | tipo: " << p.GetType();

    if (p.GetType() == "perishable") {
      std::cout << " | caduca: " << p.GetExpirationDate();
    }
    std::cout << "\n";
  }
}

void 
Store::MakeSale() {
  std::vector<TicketLine> lines;
  double total = 0.0;

  while (true) {
    std::string id;
    std::cout << "\nID producto (0 para terminar): ";
    std::cin >> id;

    if (id == "0") break;

    Product* p = FindById(id);
    if (!p) {
      std::cout << "Producto no encontrado.\n";
      continue;
    }

    int qty;
    std::cout << "Cantidad: ";
    std::cin >> qty;

    if (!p->Consume(qty)) {
      std::cout << "No hay stock suficiente.\n";
      continue;
    }

    double lineTotal = p->GetPrice() * qty;
    total += lineTotal;

    // --- Aquí se crea el TicketLine ---
    lines.push_back({
        p->GetId(),
        p->GetName(),
        qty,
        p->GetPrice(),
        lineTotal
      });

    std::cout << "Agregado: " << p->GetName()
      << " x" << qty << " = $" << lineTotal << "\n";
  }

  if (!lines.empty()) {
    std::cout << "\nTOTAL VENTA: $" << total << "\n";
    SaveTicket(lines, total);
    SaveInventory("inventory.json");
  }
  else {
    std::cout << "No se registró ningún producto.\n";
  }
}

void 
Store::AddProductInteractive() {
  std::string id, name, type, expiration;
  double price;
  int stock;

  std::cout << "ID nuevo producto (ej. A123): ";
  std::cin >> id;

  if (FindById(id)) {
    std::cout << "Ya existe un producto con ese ID.\n";
    return;
  }
  // LIMPIA el salto de línea que deja std::cin >>
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Nombre del producto (puede contener espacios): ";
  std::getline(std::cin, name);

  std::cout << "Precio: ";
  std::cin >> price;

  std::cout << "Stock inicial: ";
  std::cin >> stock;

  std::cout << "Tipo (perishable / non_perishable): ";
  std::cin >> type;

  if (type == "perishable") {
    std::cout << "Fecha de caducidad (YYYY-MM-DD): ";
    std::cin >> expiration;
  }

  auto prod = std::make_unique<Product>(id, name, price, stock, type, expiration);
  m_products.push_back(std::move(prod));

  SaveInventory("inventory.json");

  std::cout << "Producto agregado y guardado.\n";
}

void 
Store::SaveTicket(const std::vector<TicketLine>& lines, double total) const {
  // Nombre con timestamp
  std::time_t t = std::time(nullptr);
  std::tm* tmPtr = std::localtime(&t);
  char buffer[64];

  std::strftime(buffer, sizeof(buffer),
    "ticket_%Y%m%d_%H%M%S.txt", tmPtr);
  std::string fileName = buffer;

  std::ofstream out(fileName);
  if (!out.is_open()) {
    std::cout << "No se pudo guardar el ticket en " << fileName << "\n";
    return;
  }

  out << "=== TICKET DE VENTA ===\n\n";

  for (const auto& line : lines) {
    out << line.productId << " - "
      << line.productName
      << " x" << line.quantity
      << " @ " << line.unitPrice
      << " = " << line.lineTotal << "\n";
  }

  out << "\nTOTAL: " << total << "\n";

  std::cout << "Ticket guardado en: " << fileName << "\n";
}

void 
Store::SaveInventory(const std::string& filePath) const {
  nlohmann::json j;
  j["products"] = nlohmann::json::array();

  for (const auto& up : m_products) {
    ProductDTO dto = up->ToDTO();
    j["products"].push_back(dto);
  }

  std::ofstream out(filePath);
  if (!out.is_open()) {
    std::cout << "No se pudo guardar el inventario.\n";
    return;
  }

  out << j.dump(4);   // 4 = indentación bonita
  std::cout << "Inventario guardado correctamente.\n";
}

Product* 
Store::FindById(const std::string& id) {
  for (auto& up : m_products) {
    if (up->GetId() == id) {
      return up.get();          // devolvemos puntero crudo (no propietario)
    }
  }
  return nullptr;
}
