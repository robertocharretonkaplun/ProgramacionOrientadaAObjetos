#include "Prerequisites.h"
#include "Cadena.h"


int main() {
    Cadena nombre("Jugador1");
  
    std::cout << "Nombre: " << nombre.cstr() << "\n";
    std::cout << "Longitud: " << nombre.length() << "\n";
  
    // Al salir de main, ~Cadena() libera la memoria.
  
    Cadena mensaje("Hola");
    std::cout << mensaje.cstr() << "\n";
  
    mensaje.set("Bienvenido al juego");
    std::cout << mensaje.cstr() << "\n";
    return 0;
  return 0;
}
