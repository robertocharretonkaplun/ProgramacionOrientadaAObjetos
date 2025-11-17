#include <iostream>
using namespace std;

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

  cout << "=== Mini Combate en C++ ===\n";
  cout << "El enemigo tiene " << vidaEnemigo << " puntos de vida.\n";

  while (vidaEnemigo > 0) {

    cout << "\nTurno #" << turno << endl;

    int opcion;
    cout << "Elige tu accion: (1) Golpe normal  (2) Golpe critico: ";
    cin >> opcion;

    if (opcion != 1 && opcion != 2) {
      cout << "Opcion invalida. Pierdes el turno.\n";
      turno++;
      continue;
    }

    bool critico = (opcion == 2);
    int danio = CalcularDanio(ataqueJugador, critico);

    vidaEnemigo -= danio;

    cout << "Atacaste e hiciste " << danio << " puntos de danio.\n";
    cout << "Vida restante del enemigo: " << 
      (vidaEnemigo > 0 ? vidaEnemigo : 0) << endl;

    turno++;
  }

  cout << "\n¡Felicidades! Derrotaste al enemigo.\n";
  return 0;
}
