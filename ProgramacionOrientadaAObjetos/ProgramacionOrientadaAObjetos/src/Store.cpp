#include "PuntoDeVenta\Store.h"

bool 
Store::LoadInventory(const std::string& filePath) {
	std::ifstream file(filePath);

	if (!file.is_open()) {
		std::cout << "No se pudo abrir " << filePath << "\n";
		return false;
	}

	json j;
	file >> j;


	return false;
}
