#include "Prerequisites.h"
#include "Player.h"

int main() {
  // ------------------------------
//  Ejemplo usando la CLASE Player
// ------------------------------
  Player jugador("Roberto", 100, 5.5f);
  jugador.PrintInfo();


  // ------------------------------
  //  Ejemplo usando la STRUCT Vector3
  // ------------------------------
  Vector3 posicionInicial(10.0f, 2.5f, -4.0f);
  posicionInicial.Print();

  // Cambio directo de valores (porque struct es pública por defecto)
  posicionInicial.x = 20.0f;
  posicionInicial.y = 3.0f;
  posicionInicial.z = 0.0f;

  std::cout << "Nueva posicion: ";
  posicionInicial.Print();

  return 0;
}
