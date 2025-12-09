#pragma once
#include "Prerequisites.h"
#include "Figura.h"

/**
 * @brief Cuadrado con un lado definido.
 */
class Cuadrado : public Figura {
private:
  float lado;

public:
  Cuadrado(float l) : lado(l) {}
  float Area() const override { return lado * lado; }
};