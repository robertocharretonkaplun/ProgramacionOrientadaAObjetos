#pragma once
#include "Prerequisites.h"

/**
 * @brief Representa a un jugador dentro del videojuego.
 */
class Player {
private:
    std::string name;
    int health;
    float speed;

public:
    /**
     * @brief Constructor del jugador.
     * @param n Nombre del jugador.
     * @param h Vida inicial del jugador.
     * @param s Velocidad inicial del jugador.
     */
    Player(const std::string& n, int h, float s)
        : name(n), health(h), speed(s) {}

    /**
     * @brief Muestra la información del jugador.
     */
    void PrintInfo() const {
        std::cout << "Player: " << name
                  << " | Health: " << health
                  << " | Speed: " << speed << "\n";
    }
};

/**
 * @brief Estructura simple que representa una posición 3D.
 */
struct Vector3 {
  float x;
  float y;
  float z;

  /**
   * @brief Constructor para inicializar el vector.
   * @param px Posición en X.
   * @param py Posición en Y.
   * @param pz Posición en Z.
   */
  Vector3(float px, float py, float pz)
    : x(px), y(py), z(pz) {
  }

  /**
   * @brief Imprime la posición.
   */
  void Print() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")\n";
  }
};
