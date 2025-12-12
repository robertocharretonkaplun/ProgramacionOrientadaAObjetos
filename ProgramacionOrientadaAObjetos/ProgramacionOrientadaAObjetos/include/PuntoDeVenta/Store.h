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