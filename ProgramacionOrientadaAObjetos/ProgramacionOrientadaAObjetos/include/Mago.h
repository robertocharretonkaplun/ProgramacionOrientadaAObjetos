#pragma once
#include "Prerequisites.h"
#include "Personaje.h"

class Mago : public Personaje {
public:
  Mago(const std::string& nombre)
    : Personaje(nombre, 100, 10) {
  }

  void LanzarHechizo() const {
    std::cout << nombre << " lanza un hechizo de fuego (daño 40).\n";
  }
};
