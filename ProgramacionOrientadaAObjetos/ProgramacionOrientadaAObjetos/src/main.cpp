#include "Prerequisites.h"
#include "Perro.h"

int main() {
  Perro p("Firulais", 3);

  p.Comer();    // Método heredado
  p.Dormir();   // Método heredado
  p.Ladrar();   // Método propio de Perro
  return 0;
}
