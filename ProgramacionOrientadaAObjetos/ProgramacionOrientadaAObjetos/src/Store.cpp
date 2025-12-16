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

Product* 
Store::FindById(const std::string& id) {
  for (auto& up : m_products) {
    if (up->GetId() == id) {
      return up.get();          // devolvemos puntero crudo (no propietario)
    }
  }
  return nullptr;
}
