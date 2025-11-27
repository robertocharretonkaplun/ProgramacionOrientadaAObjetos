#pragma once
#include "Prerequisites.h"

/**
 * @brief Representa un vector 2D usado en cálculos típicos de videojuegos,
 * incluyendo física, movimiento, transformaciones y operaciones matemáticas comunes.
 */
class Vector2D {
private:
  float x, y;

public:
  // -------------------------------------------------------------------------
  // CONSTRUCTORES
  // -------------------------------------------------------------------------

  /// @brief Constructor por defecto. Inicializa el vector en (0, 0).
  Vector2D() : x(0.0f), y(0.0f) {}

  /// @brief Constructor principal.
  Vector2D(float x, float y) : x(x), y(y) {}

  /// @brief Constructor de copia.
  Vector2D(const Vector2D& other) : x(other.x), y(other.y) {}

  // -------------------------------------------------------------------------
  // GETTERS Y SETTERS
  // -------------------------------------------------------------------------

  float GetX() const { return x; }
  float GetY() const { return y; }
  void SetX(float value) { x = value; }
  void SetY(float value) { y = value; }

  /// @brief Establece ambos valores del vector.
  void Set(float newX, float newY) { x = newX; y = newY; }

  // -------------------------------------------------------------------------
  // MAGNITUD Y NORMALIZACIÓN
  // -------------------------------------------------------------------------

  float Magnitude() const {
    return std::sqrt(x * x + y * y);
  }

  float SqrMagnitude() const {
    return (x * x + y * y);
  }

  void Normalize() {
    float m = Magnitude();
    if (m > 0.0f) {
      x /= m;
      y /= m;
    }
  }

  /// @brief Devuelve una versión normalizada del vector sin modificar el original.
  Vector2D Normalized() const {
    float m = Magnitude();
    if (m == 0.0f) return Vector2D(0, 0);
    return Vector2D(x / m, y / m);
  }

  // -------------------------------------------------------------------------
  // OPERACIONES VECTORIALES
  // -------------------------------------------------------------------------

  /// @brief Producto punto entre este vector y otro.
  float Dot(const Vector2D& other) const {
    return (x * other.x + y * other.y);
  }

  /// @brief Distancia entre dos vectores.
  float Distance(const Vector2D& other) const {
    float dx = x - other.x;
    float dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
  }

  /// @brief Devuelve un vector perpendicular (rotado 90°).
  Vector2D Perpendicular() const {
    return Vector2D(-y, x);
  }

  /// @brief Limita la magnitud del vector.
  void ClampMagnitude(float maxLength) {
    float m = Magnitude();
    if (m > maxLength) {
      Normalize();
      x *= maxLength;
      y *= maxLength;
    }
  }

  // -------------------------------------------------------------------------
  // SOBRECARGA DE OPERADORES
  // -------------------------------------------------------------------------

  Vector2D operator+(const Vector2D& rhs) const {
    return Vector2D(x + rhs.x, y + rhs.y);
  }

  Vector2D operator-(const Vector2D& rhs) const {
    return Vector2D(x - rhs.x, y - rhs.y);
  }

  Vector2D& operator+=(const Vector2D& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  Vector2D& operator-=(const Vector2D& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  Vector2D operator*(float scalar) const {
    return Vector2D(x * scalar, y * scalar);
  }

  Vector2D operator/(float scalar) const {
    return Vector2D(x / scalar, y / scalar);
  }

  Vector2D& operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
  }

  Vector2D& operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
  }

  /// @brief Operador unario negativo.
  Vector2D operator-() const {
    return Vector2D(-x, -y);
  }

  /// @brief Comparación por igualdad.
  bool operator==(const Vector2D& rhs) const {
    return (x == rhs.x && y == rhs.y);
  }

  bool operator!=(const Vector2D& rhs) const {
    return !(*this == rhs);
  }

  // -------------------------------------------------------------------------
  // UTILIDADES
  // -------------------------------------------------------------------------

  /// @brief Interpolación lineal (lerp) entre dos vectores.
  static Vector2D Lerp(const Vector2D& a, const Vector2D& b, float t) {
    return Vector2D(
      a.x + (b.x - a.x) * t,
      a.y + (b.y - a.y) * t
    );
  }

  /// @brief Devuelve un string con el formato "(x, y)".
  std::string ToString() const {
    std::ostringstream os;
    os << "(" << x << ", " << y << ")";
    return os.str();
  }
};

