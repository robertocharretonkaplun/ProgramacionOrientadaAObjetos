#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Prerequisites.h"
#include "Product.h"

struct TicketLine {
  std::string productId;
  std::string productName;
  int         quantity;
  double      unitPrice;
  double      lineTotal;
};

// Struct plano que coincide con el JSON
struct ProductDTO {
  std::string id;
  std::string name;
  double      price;
  int         stock;
  std::string type;
  std::string expirationDate;
};

class Store {
public:
  bool LoadInventory(const std::string& filePath);
  void ShowInventory() const;
  void MakeSale();
  void AddProductInteractive();
  void SaveTicket(const std::vector<TicketLine>& lines,
    double total) const;

private:
  std::vector<std::unique_ptr<Product>> products_;

  Product* FindById(const std::string& id);
  void SaveTicket(const std::vector<std::pair<Product, int>>& lines,
    double total) const;
};