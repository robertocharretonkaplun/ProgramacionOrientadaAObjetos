#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase simple para representar un enemigo.
 */
class Enemy {
public:
  Enemy() { std::cout << "Spawn de enemigo.\n"; }
  ~Enemy() { std::cout << "Enemigo destruido.\n"; }
};

//int main() {
//  Enemy* e = new Enemy();   // Instancia dinámica
//  // ... lógica del juego ...
//  delete e;                 // Evitar fugas de memoria
//}

