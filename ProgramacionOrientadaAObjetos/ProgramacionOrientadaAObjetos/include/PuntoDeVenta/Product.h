#pragma once
#include "Prerequisites.h"

class Product {
public:
  Product() = default;

  Product(const std::string& id,
          const std::string& name,
          double price,
          int stock,
          const std::string& type,
          const std::string& expirationDate = "")
    : m_id(id),
      m_name(name),
      m_price(price),
      m_stock(stock),
      m_type(type),
      m_expirationDate(expirationDate) {
  }

  const std::string& GetId() const { return m_id; }
  const std::string& GetName() const { return m_name; }
  double GetPrice() const { return m_price; }
  int GetStock() const { return m_stock; }
  const std::string& GetType() const { return m_type; }
  const std::string& GetExpirationDate() const { return m_expirationDate; }

  bool Consume(int quantity) {
    if (quantity <= 0 || quantity > m_stock) return false;
    m_stock -= quantity;
    return true;
  }

public:
  std::string m_id;
  std::string m_name;
  double      m_price{ 0.0 };
  int         m_stock{ 0 };
  std::string m_type;
  std::string m_expirationDate;
};