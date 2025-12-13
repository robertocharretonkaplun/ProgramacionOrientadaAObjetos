// Product.h
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
  const std::string& GetExpirationDate() const { return expirationDate_; }

  bool Consume(int quantity) {
    if (quantity <= 0 || quantity > stock_) return false;
    stock_ -= quantity;
    return true;
  }

  ProductDTO ToDTO() const {
    return ProductDTO{
        id_,
        name_,
        price_,
        stock_,
        type_,
        expirationDate_
    };
  }

public:
  std::string id_;
  std::string name_;
  double      price_{ 0.0 };
  int         stock_{ 0 };
  std::string type_;
  std::string expirationDate_;
};
