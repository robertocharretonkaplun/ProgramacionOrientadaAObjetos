#pragma once
#include "Prerequisites.h"
#include "Product.h"

struct TicketLine {
  std::string productId;
  std::string productName;
  int         quantity;
  double      unitPrice;
  double      lineTotal;
};

class 
Store {
public:
  bool LoadInventory(const std::string& filePath);
  void ShowInventory() const;
  void MakeSale();
  void AddProductInteractive();
  void SaveTicket(const std::vector<TicketLine>& lines,
    double total) const;
  void SaveInventory(const std::string& filePath) const;

private:
	Product* FindById(const std::string& id);
	void SaveTicket(const std::vector<std::pair<Product, int>>& lines,
		double total) const;
private:
	std::vector<std::unique_ptr<Product>> m_products;
};