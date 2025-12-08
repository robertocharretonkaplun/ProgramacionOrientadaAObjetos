#include "Prerequisites.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Arquero.h"


int main() {
  Guerrero g("Arthos");
  Mago m("Elandra");
  Arquero a("Sylvar");

  g.MostrarInfo();
  g.GolpeFuerte();
  g.Atacar();

  std::cout << "\n";

  m.MostrarInfo();
  m.LanzarHechizo();
  m.Atacar();

  std::cout << "\n";

  a.MostrarInfo();
  a.DisparoPreciso();
  a.Atacar();

  std::cout << "\nSimulación de daño:\n";
  g.RecibirDaño(30);
  m.RecibirDaño(50);
  a.RecibirDaño(20);

  return 0;
}
