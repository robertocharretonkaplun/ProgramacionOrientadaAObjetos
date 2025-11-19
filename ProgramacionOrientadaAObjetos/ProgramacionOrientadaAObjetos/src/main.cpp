#include "Prerequisites.h"

int CalcularDanio(int base, bool crit) {
  if (crit) {
    return base * 2;  // Daño crítico
  }
  return base;
}

int main() {
  int vidaEnemigo = 30;
  int ataqueJugador = 5;
  int turno = 1;

  std::cout << "=== Mini Combate en C++ ===\n";
  std::cout << "El enemigo tiene " << vidaEnemigo << " puntos de vida.\n";

  while (vidaEnemigo > 0) {

    std::cout << "\nTurno #" << turno << std::endl;

    int opcion;
    std::cout << "Elige tu accion: (1) Golpe normal  (2) Golpe critico: ";
    std::cin >> opcion;

    if (opcion != 1 && opcion != 2) {
      std::cout << "Opcion invalida. Pierdes el turno.\n";
      turno++;
      continue;
    }

    bool critico = (opcion == 2);
    int danio = CalcularDanio(ataqueJugador, critico);

    vidaEnemigo -= danio;

    std::cout << "Atacaste e hiciste " << danio << " puntos de danio.\n";
    std::cout << "Vida restante del enemigo: " << (vidaEnemigo > 0 ? vidaEnemigo : 0) << std::endl;

    turno++;
  }

  std::cout << "\n¡Felicidades! Derrotaste al enemigo.\n";
  return 0;
}
