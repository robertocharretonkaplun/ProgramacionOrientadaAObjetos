#pragma once
#include "Prerequisites.h"
#include "Personaje.h"

class Arquero : public Personaje {
public:
  Arquero(const std::string& nombre)
    : Personaje(nombre, 120, 15) {
  }

  void DisparoPreciso() const {
    std::cout << nombre << " realiza un disparo preciso (daño 35).\n";
  }
};
