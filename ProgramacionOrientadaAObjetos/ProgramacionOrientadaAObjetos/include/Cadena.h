#pragma once
#include "Prerequisites.h"

/**
 * @brief Cadena básica que administra su propio buffer dinámico.
 */
class Cadena {
private:
	char* data;   ///< Puntero al buffer de caracteres 
  size_t len;   ///< Longitud de la cadena (sin contar '\0')

public:
  /**
   * @brief Constructor desde cadena tipo C.
   * @param txt Cadena terminada en '\0'. Debe ser no nula.
   */
  Cadena(const char* txt)
    : data(nullptr), len(0)
  {
    if (txt) {
      len = std::strlen(txt);
      data = new char[len + 1];     // +1 para '\0'
      std::strcpy(data, txt);
    }
  }

  /**
   * @brief Destructor: libera la memoria interna.
   */
  ~Cadena() {
    delete[] data;
    data = nullptr;
    len = 0;
  }

  /**
     * @brief Asigna un nuevo contenido a la cadena.
     * @param txt Cadena terminada en '\0'.
     */
  void set(const char* txt) {
    // 1. Liberar buffer anterior
    delete[] data;
    data = nullptr;
    len = 0;

    if (!txt)
      return;

    // 2. Reservar nueva memoria
    len = std::strlen(txt);
    data = new char[len + 1];

    // 3. Copiar contenido
    std::strcpy(data, txt);
  }

  /**
   * @brief Obtiene la cadena interna de solo lectura.
   * @return Puntero const a char.
   */
  const char* cstr() const {
    return data ? data : "";
  }

  /**
   * @brief Obtiene la longitud de la cadena.
   */
  size_t length() const {
    return len;
  }
};

//int main() {
//  Cadena nombre("Jugador1");
//
//  std::cout << "Nombre: " << nombre.cstr() << "\n";
//  std::cout << "Longitud: " << nombre.length() << "\n";
//
//  // Al salir de main, ~Cadena() libera la memoria.
//
//  Cadena mensaje("Hola");
//  std::cout << mensaje.cstr() << "\n";
//
//  mensaje.set("Bienvenido al juego");
//  std::cout << mensaje.cstr() << "\n";
//  return 0;
//}
