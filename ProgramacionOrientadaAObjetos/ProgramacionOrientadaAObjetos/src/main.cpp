#include "Prerequisites.h"
#include "Figura.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Circulo.h"


int main() {
  std::vector<std::unique_ptr<Figura>> figuras;

  figuras.push_back(std::make_unique<Cuadrado>(5));
  figuras.push_back(std::make_unique<Triangulo>(4, 3));
  figuras.push_back(std::make_unique<Circulo>(10));

  for (const auto& f : figuras) {
    std::cout << "Area: " << f->Area() << "\n";
  }

  return 0;
}
