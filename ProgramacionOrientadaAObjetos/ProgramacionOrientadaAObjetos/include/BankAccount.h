#pragma once
#include "Prerequisites.h"

/**
 * @brief Representa una cuenta bancaria básica.
 *
 * Permite consultar saldo, depositar, retirar y transferir dinero
 * entre cuentas.
 */
class BankAccount {
private:
  std::string ownerName;   ///< Nombre del titular
  std::string accountId;   ///< Identificador de la cuenta
  double balance;          ///< Saldo actual

public:
  /**
   * @brief Constructor de la cuenta bancaria.
   * @param owner Nombre del titular.
   * @param id    Identificador único de la cuenta.
   * @param initialBalance Saldo inicial (>= 0).
   * @throws std::invalid_argument Si el saldo inicial es negativo.
   */
  BankAccount(const std::string& owner,
              const std::string& id,
              double initialBalance = 0.0)
    : ownerName(owner), accountId(id), balance(initialBalance)
  {
    if (initialBalance < 0.0) {
      throw std::invalid_argument("El saldo inicial no puede ser negativo.");
    }
  }

  /**
   * @brief Obtiene el nombre del titular.
   * @return Nombre del titular.
   */
  std::string GetOwnerName() const {
    return ownerName;
  }

  /**
   * @brief Obtiene el ID de la cuenta.
   * @return Identificador único de la cuenta.
   */
  std::string GetAccountId() const {
    return accountId;
  }

  /**
   * @brief Consulta el saldo actual de la cuenta.
   * @return Saldo actual.
   */
  double GetBalance() const {
    return balance;
  }

  /**
   * @brief Deposita una cantidad en la cuenta.
   * @param amount Cantidad a depositar (> 0).
   * @throws std::invalid_argument Si la cantidad es <= 0.
   */
  void Deposit(double amount) {
    if (amount <= 0.0) {
      LOG_INFO("BankAccount", "Deposit", 
      ("Intento de deposito con cantidad no valida: " + std::to_string(amount)).c_str());
			//std::cout << "El deposito debe ser mayor que 0." << std::endl;
      //throw std::invalid_argument("El deposito debe ser mayor que 0.");
    }
    balance += amount;
  }

  /**
   * @brief Retira una cantidad de la cuenta.
   * @param amount Cantidad a retirar (> 0).
   * @return true si el retiro fue exitoso, false si no hay saldo suficiente.
   * @throws std::invalid_argument Si la cantidad es <= 0.
   */
  bool Withdraw(double amount) {
    if (amount <= 0.0) {
      LOG_INFO("BankAccount", "Withdraw", 
				("Intento de retiro con cantidad no valida: " + std::to_string(amount)).c_str());
			std::cout << "El retiro debe ser mayor que 0." << std::endl;
      //throw std::invalid_argument("El retiro debe ser mayor que 0.");
    }

    if (amount > balance) {
      return false; // saldo insuficiente
    }

    balance -= amount;
    return true;
  }

  /**
   * @brief Transfiere dinero desde esta cuenta a otra.
   * @param other Cuenta destino.
   * @param amount Monto a transferir (> 0).
   * @return true si la transferencia fue exitosa,
   *         false si no hay saldo suficiente.
   * @throws std::invalid_argument Si la cantidad es <= 0.
   * @note Internamente realiza un Withdraw() y luego Deposit() en la cuenta destino.
   */
  bool TransferTo(BankAccount& other, double amount) {
    if (amount <= 0.0) {
			LOG_INFO("BankAccount", "TransferTo",
				("Intento de transferencia con cantidad no valida: " + std::to_string(amount)).c_str());
			std::cout << "La transferencia debe ser mayor que 0." << std::endl;
      //throw std::invalid_argument("La transferencia debe ser mayor que 0.");
    }

    if (!Withdraw(amount)) {
			LOG_INFO("BankAccount", "TransferTo",
				("No se pudo completar la transferencia de " + std::to_string(amount) +
					" desde la cuenta " + accountId + " a la cuenta " + other.accountId +
					" por saldo insuficiente.").c_str());
			std::cout << "Saldo insuficiente para la transferencia." << std::endl;
      return false; // no se pudo retirar de la cuenta origen
    }
    other.Deposit(amount);
    return true;
  }
  /**
   * @brief Imprime un resumen simple de la cuenta.
   */
  void PrintSummary() const {
    std::cout << "Cuenta: " << accountId
      << " | Titular: " << ownerName
      << " | Saldo: " << balance << std::endl;
  }
};

