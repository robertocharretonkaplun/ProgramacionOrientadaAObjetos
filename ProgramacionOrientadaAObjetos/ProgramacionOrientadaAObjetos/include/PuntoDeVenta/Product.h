// Product.h
#pragma once
#include "Prerequisites.h"

/**
 * @brief Representa un producto simple de la tienda.
 */
class Product {
public:
  Product() = default;

  Product(const std::string& id,
    const std::string& name,
    double price,
    int stock,
    const std::string& type,
    const std::string& expirationDate = "")
    : id_(id),
    name_(name),
    price_(price),
    stock_(stock),
    type_(type),
    expirationDate_(expirationDate) {
  }

  const std::string& GetId() const { return id_; }
  const std::string& GetName() const { return name_; }
  double GetPrice() const { return price_; }
  int GetStock() const { return stock_; }
  const std::string& GetType() const { return type_; }

  /// @brief Devuelve la fecha de caducidad (vacía si no aplica).
  const std::string& GetExpirationDate() const { return expirationDate_; }

  void SetName(const std::string& name) { name_ = name; }
  void SetPrice(double price) { price_ = price; }
  void SetStock(int stock) { stock_ = stock; }
  void SetType(const std::string& type) { type_ = type; }
  void SetExpirationDate(const std::string& date) { expirationDate_ = date; }

  /// @brief Intenta descontar stock. Devuelve true si fue posible.
  bool Consume(int quantity) {
    if (quantity <= 0 || quantity > stock_) {
      return false;
    }
    stock_ -= quantity;
    return true;
  }

private:
  std::string id_{ "" };
  std::string name_{ "" };
  double      price_{ 0.0 };
  int         stock_{ 0 };

  // Nuevos campos para el JSON "bonito"
  std::string type_{ "" };          // "perishable" o "non_perishable"
  std::string expirationDate_{ "" };// solo se usa si type == "perishable"
};
