#pragma once
#include "Prerequisites.h"
#include "VirtualRPG\Personaje.h"

/// @brief Representa un Guerrero dentro del sistema de combate.
class Guerrero : public Personaje {
public:
  /**
   * @brief Constructor de Guerrero.
   * @param nombre Nombre del guerrero.
   */
  explicit Guerrero(const std::string& nombre)
    : Personaje(nombre) {
  }

  /// @brief Implementación específica del ataque de un Guerrero.
  void Atacar() const override {
    std::cout << nombre
      << " (Guerrero) ataca con una espada poderosa.\n";
  }

  /// @brief Muestra la clase del personaje.
  void MostrarClase() const override {
    std::cout << nombre << " es un Guerrero.\n";
  }
};
