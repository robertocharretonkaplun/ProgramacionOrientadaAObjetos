#pragma once
#include "Prerequisites.h"

class Lapiz {
public:
  int grosor;

  Lapiz(int g = 2) : grosor(g) {}

  void Escribir() const {
    std::cout << "El lápiz escribe con grosor " << grosor << "\n";
  }
};

class Mochila {
private:
  Lapiz lapiz;  // COMPOSICIÓN

public:
  Mochila() : lapiz(2) {}

  void UsarLapiz() {
    lapiz.Escribir();
  }
};

class Alumno {
private:
  Mochila* mochila; // AGREGACIÓN

public:
  void AsignarMochila(Mochila* m) {
    mochila = m;
  }

  void UsarMochila() {
    if (mochila)
      mochila->UsarLapiz();
    else
      std::cout << "No tengo mochila.\n";
  }
};
//
//int main() {
//  Mochila miMochila;
//  Alumno juan;
//
//  juan.AsignarMochila(&miMochila);
//  juan.UsarMochila();
//
//  return 0;
//}
