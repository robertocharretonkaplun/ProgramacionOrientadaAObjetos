#pragma once
#include "Prerequisites.h"

/// @brief Representa un motor básico.
class Motor {
private:
  int caballos;

public:
  Motor(int hp)
    : caballos(hp)
  {
    std::cout << "Motor creado con " << caballos << " HP\n";
  }

  ~Motor() {
    std::cout << "Motor destruido\n";
  }

  int GetHP() const {
    return caballos;
  }
};

/// @brief Representa una rueda simple.
class Rueda {
private:
  float presion;

public:
  Rueda(float p = 32.0f)
    : presion(p)
  {
    std::cout << "Rueda creada con presion " << presion << "\n";
  }

  ~Rueda() {
    std::cout << "Rueda destruida\n";
  }

  float GetPresion() const {
    return presion;
  }
};

/// @brief Coche que tiene un motor y cuatro ruedas (composición).
class Coche {
private:
  Motor motor;      ///< Miembro por valor: el coche ES dueño del motor
  Rueda ruedas[4];  ///< Miembros por valor: el coche ES dueño de las ruedas

public:
  /// @brief Constructor: crea motor y ruedas junto con el coche.
  Coche()
    : motor(120),          // Se construye primero el motor
    ruedas{ Rueda(32),   // Luego las ruedas (inicializador agregado)
             Rueda(32),
             Rueda(34),
             Rueda(34) }
  {
    std::cout << "Coche creado\n";
  }

  /// @brief Destructor: destruye primero el coche y luego sus miembros.
  ~Coche() {
    std::cout << "Coche destruido\n";
  }

  int GetMotorHP() const {
    return motor.GetHP();
  }

  float GetPresionRueda(size_t index) const {
    if (index < 4) {
      return ruedas[index].GetPresion();
    }
    return 0.0f;
  }
};
