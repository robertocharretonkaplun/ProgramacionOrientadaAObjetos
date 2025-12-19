#include "Prerequisites.h"
#include "PuntoDeVenta\Store.h"

int main() {
	Store store;
	store.LoadInventory("inventory.json");

	int option = -1;
	while (option != 0) {
		std::cout << "\n=== MENU TIENDA ===\n";
		std::cout << "1) Ver inventario\n";
		std::cout << "2) Registrar venta\n";
		std::cout << "3) Alta de producto\n";
		std::cout << "0) Salir\n";
		std::cout << "Opcion: ";
		std::cin >> option;

		switch (option) {
		case 1: 
			system("cls||clear");
			store.ShowInventory(); 
			break;
		case 2: 
			system("cls||clear");
			store.ShowInventory(); 
			store.MakeSale();      
			break;
		case 3: 
			system("cls||clear");
			store.AddProductInteractive(); 
			break;
		case 0: 
			system("cls||clear");
			std::cout << "Saliendo...\n"; 
			break;
		default: std::cout << "Opcion invalida.\n"; break;
		}
	}
  return 0;
}
