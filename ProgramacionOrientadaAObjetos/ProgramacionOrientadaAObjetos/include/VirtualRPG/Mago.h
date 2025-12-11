#pragma once
#include "Prerequisites.h"
#include "VirtualRPG/Personaje.h"

/// @brief Representa un Mago dentro del sistema de combate.
class Mago : public Personaje {
public:
  /**
   * @brief Constructor de Mago.
   * @param nombre Nombre del mago.
   */
  explicit Mago(const std::string& nombre)
    : Personaje(nombre) {
  }

  /// @brief Implementación específica del ataque de un Mago.
  void Atacar() const override {
    std::cout << nombre
      << " (Mago) lanza un poderoso hechizo de fuego.\n";
  }

  /// @brief Muestra la clase del personaje.
  void MostrarClase() const override {
    std::cout << nombre << " es un Mago.\n";
  }
};