#include "Prerequisites.h"
#include "Vector2D.h"

int main() {
  // Crear dos vectores
  Vector2D a(3.0f, 4.0f);
  Vector2D b(1.0f, 2.0f);

  std::cout << "Vector A: " << a.ToString() << "\n";
  std::cout << "Vector B: " << b.ToString() << "\n\n";

  // Magnitud
  std::cout << "Magnitud de A: " << a.Magnitude() << "\n\n";

  // Normalizar
  Vector2D aNorm = a.Normalized();
  std::cout << "A Normalizado: " << aNorm.ToString() << "\n\n";

  // Suma
  Vector2D c = a + b;
  std::cout << "A + B = " << c.ToString() << "\n";

  // Resta
  Vector2D d = a - b;
  std::cout << "A - B = " << d.ToString() << "\n";

  // Multiplicación por escalar
  Vector2D e = a * 3.0f;
  std::cout << "A * 3 = " << e.ToString() << "\n\n";

  // Distancia entre vectores
  std::cout << "Distancia entre A y B: " << a.Distance(b) << "\n\n";

  // Producto punto
  float dot = a.Dot(b);
  std::cout << "A x B = " << dot << "\n\n";

  // Vector perpendicular
  Vector2D p = a.Perpendicular();
  std::cout << "Perpendicular de A: " << p.ToString() << "\n\n";

  // Clamp Magnitude
  Vector2D f(10.0f, 5.0f);
  std::cout << "Vector F original: " << f.ToString() << "\n";
  f.ClampMagnitude(5.0f);
  std::cout << "Vector F con magnitud limitada a 5: " << f.ToString() << "\n\n";

  // Lerp
  Vector2D lerpResult = Vector2D::Lerp(a, b, 0.5f);
  std::cout << "Lerp(A, B, 0.5) = " << lerpResult.ToString() << "\n";
  return 0;
}
