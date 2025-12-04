#include "Prerequisites.h"
#include "Motor.h"
#include "Conductor.h"


int main() {
  Conductor juan("Juan Perez");   // Vive independientemente
  Conductor ana("Ana Lopez");

  CocheConductor cocheA;
  CocheConductor cocheB;

  cocheA.SetConductor(&juan);     // cocheA usa a Juan
  cocheB.SetConductor(&ana);      // cocheB usa a Ana

  cocheA.ImprimirConductor();
  cocheB.ImprimirConductor();

  // Incluso podrías reasignar
  cocheA.SetConductor(&ana);      // Ahora cocheA usa a Ana
  cocheA.ImprimirConductor();

  // Cuando los coches se destruyen (al final de main),
  // juan y ana SIGUEN siendo válidos hasta el final del programa.
  return 0;
}
