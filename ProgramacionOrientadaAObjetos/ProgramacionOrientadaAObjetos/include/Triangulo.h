#pragma once
#include "Prerequisites.h"
#include "Figura.h"

/**
 * @brief Triángulo con base y altura.
 */
class Triangulo : public Figura {
private:
  float base, altura;

public:
  Triangulo(float b, float h) : base(b), altura(h) {}
  float Area() const override { return (base * altura) / 2.0f; }
};