#pragma once
#include "Prerequisites.h"
/**
 * @brief Representa un usuario dentro de un sistema de registro.
 */
class User {
private:
  std::string username;
  std::string email;
  std::string passwordHash;

  bool IsValidEmail(const std::string& e) const {
    return e.find('@') != std::string::npos;
  }

  std::string HashPassword(const std::string& pass) const {
    return "HASH_" + pass;
  }

public:

  // 1. CONSTRUCTOR POR DEFECTO
  /**
   * @brief Constructor por defecto.
   * @note Crea un usuario vacío o temporal.
   */
  User() : username("Guest"), 
           email("not_provided"), 
           passwordHash(HashPassword("guest")) { }

  // 2. CONSTRUCTOR PARAMETRIZADO (mínimo)
  /**
   * @brief Constructor básico: username + password.
   */
  User(const std::string& uname, const std::string& pass)
    : username(uname),
      email("not_provided"),
      passwordHash(HashPassword(pass)) {
    if (uname.empty()) throw std::invalid_argument("Username cannot be empty.");
    if (pass.size() < 4) throw std::invalid_argument("Password too short.");
  }

  // 3. CONSTRUCTOR PARAMETRIZADO (completo, sobrecarga)
  /**
   * @brief Constructor completo: username + email + password.
   */
  User(const std::string& uname, 
       const std::string& mail, 
       const std::string& pass)
      : username(uname),
        email(mail),
        passwordHash(HashPassword(pass)) {
    if (uname.empty()) throw std::invalid_argument("Username cannot be empty.");
    if (!IsValidEmail(mail)) throw std::invalid_argument("Invalid email format.");
    if (pass.size() < 4) throw std::invalid_argument("Password too short.");
  }

  // 4. CONSTRUCTOR DE COPIA
  /**
   * @brief Constructor de copia.
   * @note Copia segura de los datos de otro usuario.
   */
  User(const User& other)
    : username(other.username),
      email(other.email),
      passwordHash(other.passwordHash)  // El hash se copia, NO la contraseña
  {}

  // 5. CONSTRUCTOR DE MOVIMIENTO
  /**
   * @brief Constructor de movimiento (C++11).
   * @note Optimiza cuando un User temporal es movido.
   */
  User(User&& other) noexcept
    : username(std::move(other.username)),
      email(std::move(other.email)),
      passwordHash(std::move(other.passwordHash)) {
    // Estado seguro para el objeto movido
    other.username = "moved_user";
    other.email = "moved_email";
    other.passwordHash = "moved_hash";
  }

  // Métodos de la clase (getters/setters)
  const std::string& GetUsername() const { return username; }
  const std::string& GetEmail() const { return email; }

  void SetEmail(const std::string& mail) {
    if (IsValidEmail(mail))
      email = mail;
  }

  void ChangePassword(const std::string& newPass) {
    if (newPass.size() >= 4)
      passwordHash = HashPassword(newPass);
  }

  void PrintInfo() const {
    std::cout << "User: " << username
      << " | Email: " << email << "\n";
  }
};
