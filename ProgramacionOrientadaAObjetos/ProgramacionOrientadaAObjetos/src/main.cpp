#include "Prerequisites.h"
#include "User.h"

int main() {
    // Crear usuarios con diferentes constructores
    User defaultUser;
    User basicUser("john_doe", "securePass123");
    User fullUser("jane_doe", "pcidvmexico@gmail.com", "another");
		User copiedUser(basicUser);
    User movedUser(std::move(fullUser));
    // Mostrar información de los usuarios
    defaultUser.PrintInfo();
    basicUser.PrintInfo();
    copiedUser.PrintInfo();
		movedUser.PrintInfo();


  return 0;
}
