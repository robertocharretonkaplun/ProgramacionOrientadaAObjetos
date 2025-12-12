#pragma once
/// Inventory.h
#pragma once
#include "Prerequisites.h"
#include "Product.h"

/**
 * @brief Gestiona la colección de productos de la tienda.
 */
class Inventory {
public:
  /**
   * @brief Agrega un producto al inventario.
   * @param product Puntero único al producto.
   *
   * @note La función toma posesión del puntero.
   */
  void AddProduct(std::unique_ptr<Product> product);

  /**
   * @brief Busca un producto por ID.
   * @param id Identificador del producto.
   * @return Puntero crudo (no propietario) o nullptr.
   */
  Product* FindById(const std::string& id);

  /**
   * @brief Devuelve la lista de productos.
   * @return Referencia constante al vector interno.
   */
  const std::vector<std::unique_ptr<Product>>& GetProducts() const {
    return products_;
  }

private:
  std::vector<std::unique_ptr<Product>> products_;
};
