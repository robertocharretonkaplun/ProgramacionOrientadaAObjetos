#pragma once
#include "Prerequisites.h"
#include "Animal.h"

class Perro : public Animal {
public:
  // Constructor de Perro que llama al constructor de Animal
  Perro(const std::string& nombre, int edad)
    : Animal(nombre, edad) {
  }

  void Ladrar() const {
    std::cout << nombre << " dice: ¡Guau!\n";
  }
};

//int main() {
//  Perro p("Firulais", 3);
//
//  p.Comer();    // Método heredado
//  p.Dormir();   // Método heredado
//  p.Ladrar();   // Método propio de Perro
//
//  return 0;
//}
//
//int main() {
//	Perro* p = new Perro("Firulais", 3);
//
//	// Vector de Animales
//	std::vector<Animal*> animales;
//
//	animales.push_back(new Perro("Memo", 15));
//	animales.push_back(new Perro("Luna", 5));
//	animales.push_back(p);
//
//	for (const auto& animal : animales) {
//		animal->Comer();
//		animal->Dormir();
//	}
//
//	// Liberar memoria
//	for (const auto& animal : animales) {
//		delete animal;
//	}
//
//	return 0;
//}
