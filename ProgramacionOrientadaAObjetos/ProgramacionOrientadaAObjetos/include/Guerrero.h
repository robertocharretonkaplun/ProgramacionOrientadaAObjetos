#pragma once
#include "Prerequisites.h"
#include "Personaje.h"

class Guerrero : public Personaje {
public:
  Guerrero(const std::string& nombre)
    : Personaje(nombre, 150, 20) {
  }

  void GolpeFuerte() const {
    std::cout << nombre << " usa Golpe Fuerte (daño 50).\n";
  }
};