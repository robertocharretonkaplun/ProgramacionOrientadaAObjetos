#pragma once
#include "Prerequisites.h"
class Persona {
private:
  std::string nombre;
  int edad;

public:
  // Constructor normal
  Persona(const std::string& n, int e)
    : nombre(n), edad(e) {
    std::cout << "[Constructor] Creando Persona: "
      << nombre << ", Edad: " << edad << "\n";
  }

  // Constructor de copia
  Persona(const Persona& other)
    : nombre(other.nombre), edad(other.edad) {
    std::cout << "[Constructor de copia] Copiando Persona: "
      << nombre << ", Edad: " << edad << "\n";
  }

  // Destructor
  ~Persona() {
    std::cout << "[Destructor] Destruyendo Persona: "
      << nombre << "\n";
  }

  void Mostrar() const {
    std::cout << "Nombre: " << nombre
      << " | Edad: " << edad << "\n";
  }
};