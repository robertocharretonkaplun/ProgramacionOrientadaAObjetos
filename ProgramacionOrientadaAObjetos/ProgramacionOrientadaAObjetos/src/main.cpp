#include "Prerequisites.h"
#include "Persona.h"

int main() {
  // Crear un objeto con el constructor normal
  Persona p1("Roberto", 28);
  p1.Mostrar();

  // Crear un objeto usando el constructor de copia
  Persona p2 = p1;
  p2.Mostrar();

  return 0;
}

