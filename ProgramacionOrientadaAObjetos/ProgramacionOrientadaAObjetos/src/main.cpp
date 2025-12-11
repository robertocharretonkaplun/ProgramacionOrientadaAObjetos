#include "Prerequisites.h"
#include "VirtualRPG/Personaje.h"
#include "VirtualRPG/Guerrero.h"
#include "VirtualRPG/Mago.h"
#include "VirtualRPG/Arquero.h"

int main() {
  // Vector polimórfico que almacena diferentes tipos de personajes
  std::vector<std::unique_ptr<Personaje>> personajes;

  // Creación de personajes usando std::make_unique (propiedad exclusiva)
  personajes.push_back(std::make_unique<Guerrero>("Arthas"));
  personajes.push_back(std::make_unique<Mago>("Merlín"));
  personajes.push_back(std::make_unique<Arquero>("Legolas"));

  std::cout << "=== Clases de los personajes ===\n";
  for (const auto& p : personajes) {
    p->MostrarClase();   // Llamada polimórfica
  }

  std::cout << "\n=== Ataques de los personajes ===\n";
  for (const auto& p : personajes) {
    p->Atacar();         // Llamada polimórfica
  }

  // No es necesario llamar delete: unique_ptr libera automáticamente.
  return 0;
}



//#include "Figura.h"
//#include "Cuadrado.h"
//#include "Triangulo.h"
//#include "Circulo.h"
//
//
//int main() {
//  std::vector<std::unique_ptr<Figura>> figuras;
//
//  figuras.push_back(std::make_unique<Cuadrado>(5));
//  figuras.push_back(std::make_unique<Triangulo>(4, 3));
//  figuras.push_back(std::make_unique<Circulo>(10));
//
//  for (const auto& f : figuras) {
//    std::cout << "Area: " << f->Area() << "\n";
//  }
//
//  return 0;
//}
