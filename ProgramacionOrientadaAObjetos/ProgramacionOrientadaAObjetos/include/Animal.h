#pragma once
#include "Prerequisites.h"

class Animal {
protected:
  std::string nombre;
  int edad;

public:
  // Constructor
  Animal(const std::string& nombre, int edad)
    : nombre(nombre), edad(edad) {
  }

  void Comer() const {
    std::cout << nombre << " esta comiendo.\n";
  }

  void Dormir() const {
    std::cout << nombre << " esta durmiendo.\n";
  }

  void init() {

  }

  void update() {
	}

  void render() {

  }

  void destroy() {

  }

};

