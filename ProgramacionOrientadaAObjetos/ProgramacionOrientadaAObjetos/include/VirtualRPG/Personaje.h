#pragma once
#include "Prerequisites.h"

/// @brief Clase base abstracta que representa un personaje genérico.
class Personaje {
protected:
  std::string nombre;  ///< Nombre del personaje

public:
  /**
   * @brief Constructor principal de Personaje.
   * @param nombre Nombre del personaje.
   */
  explicit Personaje(const std::string& nombre)
    : nombre(nombre) {
  }

  /**
   * @brief Método puramente virtual que define el ataque del personaje.
   */
  virtual void Atacar() const = 0;

  /**
   * @brief Método puramente virtual para mostrar el tipo de personaje.
   */
  virtual void MostrarClase() const = 0;

  /// @brief Destructor virtual para permitir destrucción polimórfica.
  virtual ~Personaje() = default;
};