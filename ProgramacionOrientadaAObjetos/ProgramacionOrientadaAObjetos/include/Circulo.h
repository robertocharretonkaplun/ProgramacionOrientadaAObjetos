#pragma once
#include "Prerequisites.h"
#include "Figura.h"

/**
 * @brief Representa un círculo.
 */
class Circulo : public Figura {
private:
  float r;

public:
  Circulo(float radio) : r(radio) {}

  /**
   * @brief Calcula el área del círculo.
   * @return Área como float.
   */
  float Area() const override {
    return 3.14159f * r * r;
  }
};
