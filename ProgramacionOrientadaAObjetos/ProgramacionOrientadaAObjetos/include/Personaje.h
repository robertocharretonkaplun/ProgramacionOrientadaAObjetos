#pragma once
#include "Prerequisites.h"

class Personaje {
protected:
  std::string nombre;
  int salud;
  int ataqueBase;

public:
  Personaje(const std::string& _nombre, int _salud, int _ataqueBase)
    : nombre(_nombre), salud(_salud), ataqueBase(_ataqueBase) {
  }

  void Atacar() const {
    std::cout << nombre << " realiza un ataque básico de "
      << ataqueBase << " puntos.\n";
  }

  void RecibirDaño(int dmg) {
    salud -= dmg;
    if (salud < 0) salud = 0;

    std::cout << nombre << " recibe " << dmg
      << " de daño. Salud actual: " << salud << "\n";
  }

  void MostrarInfo() const {
    std::cout << "Personaje: " << nombre
      << " | Salud: " << salud
      << " | Ataque base: " << ataqueBase << "\n";
  }
};
