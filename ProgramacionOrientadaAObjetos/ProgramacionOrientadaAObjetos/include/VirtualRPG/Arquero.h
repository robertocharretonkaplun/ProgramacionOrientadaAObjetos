#pragma once
#include "Prerequisites.h"
#include "VirtualRPG/Personaje.h"

/// @brief Representa un Arquero dentro del sistema de combate.
class Arquero : public Personaje {
public:
  /**
   * @brief Constructor de Arquero.
   * @param nombre Nombre del arquero.
   */
  explicit Arquero(const std::string& nombre)
    : Personaje(nombre) {
  }

  /// @brief Implementación específica del ataque de un Arquero.
  void Atacar() const override {
    std::cout << nombre
      << " (Arquero) dispara una flecha precisa a distancia.\n";
  }

  /// @brief Muestra la clase del personaje.
  void MostrarClase() const override {
    std::cout << nombre << " es un Arquero.\n";
  }
};
