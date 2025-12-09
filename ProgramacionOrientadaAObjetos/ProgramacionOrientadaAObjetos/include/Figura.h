#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase base abstracta para representar una figura geométrica.
 */
class Figura {
public:
  /**
   * @brief Calcula el área de la figura.
   * @return Área como número flotante.
   */
  virtual float Area() const = 0;  ///< Método virtual puro

  virtual ~Figura() = default;
};

