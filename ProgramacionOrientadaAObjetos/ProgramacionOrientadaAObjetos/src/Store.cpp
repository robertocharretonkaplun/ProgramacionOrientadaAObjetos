#include "PuntoDeVenta\Store.h"
#include "ThirdParties\json.hpp"
using nlohmann::json;

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
  ProductDTO,
  id,
  name,
  price,
  stock,
  type,
  expirationDate
)

bool Store::LoadInventory(const std::string& filePath) {
  std::ifstream file(filePath);
  if (!file.is_open()) {
    std::cout << "No se pudo abrir " << filePath << "\n";
    return false;
  }

  json j;
  file >> j;

  products_.clear();

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

    products_.push_back(std::move(prod));
  }

  std::cout << "Inventario cargado: "
    << products_.size() << " productos.\n";

  return true;
}

Product* Store::FindById(const std::string& id) {
  for (auto& up : products_) {
    if (up->GetId() == id) {
      return up.get();          // devolvemos puntero crudo (no propietario)
    }
  }
  return nullptr;
}

void Store::ShowInventory() const {
  std::cout << "\n=== INVENTARIO ===\n";
  for (const auto& up : products_) {   // up = unique_ptr<Product>
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

void Store::MakeSale() {
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
  }
  else {
    std::cout << "No se registró ningún producto.\n";
  }
}

void Store::AddProductInteractive() {
  std::string id, name, type, expiration;
  double price;
  int stock;

  std::cout << "ID nuevo producto (ej. A123): ";
  std::cin >> id;

  if (FindById(id)) {
    std::cout << "Ya existe un producto con ese ID.\n";
    return;
  }

  std::cout << "Nombre (una palabra para simplificar): ";
  std::cin >> name;

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
  products_.push_back(std::move(prod));

  std::cout << "Producto agregado.\n";
}

void Store::SaveTicket(const std::vector<TicketLine>& lines,
  double total) const
{
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
