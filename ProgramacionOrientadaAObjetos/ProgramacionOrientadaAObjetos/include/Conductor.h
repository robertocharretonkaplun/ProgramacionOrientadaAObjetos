#pragma once
#include "Prerequisites.h"
/// @brief Representa un conductor que existe independientemente del coche.
class Conductor {
private:
  std::string nombre;

public:
  Conductor(const std::string& n)
    : nombre(n)
  {
  }

  const std::string& GetNombre() const {
    return nombre;
  }
};

/// @brief Coche que tiene agregación con Conductor.
/// El coche NO crea ni destruye al conductor, solo tiene un puntero.
class CocheConductor {
private:
  Conductor* conductor;  ///< Agregación: referencia a un objeto externo

public:
  CocheConductor()
    : conductor(nullptr)
  {
  }

  /// @brief Asigna un conductor externo.
  void SetConductor(Conductor* c) {
    conductor = c;
  }

  /// @brief Muestra quién conduce el coche.
  void ImprimirConductor() const {
    if (conductor)
      std::cout << "Conduce: " << conductor->GetNombre() << "\n";
    else
      std::cout << "Sin conductor asignado\n";
  }
};
