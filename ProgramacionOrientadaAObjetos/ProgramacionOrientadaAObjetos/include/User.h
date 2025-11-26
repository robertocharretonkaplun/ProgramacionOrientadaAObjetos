#pragma once
#include "Prerequisites.h"

class User
{
public:
	// 1. CONSTRUCTOR POR DEFECTO
	/**
	 * @brief Constructor por defecto.
	 * @note Crea un usuario vacío o temporal.
	 */
	User() : m_username("Guest"),
					 m_email("not_provided"),
					 m_passwordHash(HashPassword("guest")) {
		
	}

	// 2. CONSTRUCTOR PARAMETRIZADO (mínimo)
	/**
	 * @brief Constructor básico: username + password.
	 */
	User(const std::string& uname, const std::string& pass)
		: m_username(uname),
			m_email("not_provided"),
			m_passwordHash(HashPassword(pass)) {
		if (uname.empty()) throw std::invalid_argument("Username cannot be empty.");
		if (pass.size() < 4) throw std::invalid_argument("Password too short.");
	}

	// 3. CONSTRUCTOR PARAMETRIZADO (completo)
	User(const std::string& uname,
			 const std::string& email,
			 const std::string& pass)
		: m_username(uname),
			m_email(email),
			m_passwordHash(HashPassword(pass)) {
		if (uname.empty()) throw std::invalid_argument("Username cannot be empty.");
		if (!IsValidEmail(m_email)) throw std::invalid_argument("Invalid email format.");
		if (pass.size() < 4) throw std::invalid_argument("Password too short.");
	}

	// 4. CONSTRUCTOR DE COPIA
	/**
	 * @brief Constructor de copia.
	 * @note Copia segura de los datos de otro usuario.
	 */
	User(const User& other)
		: m_username(other.m_username),
		  m_email(other.m_email),
		  m_passwordHash(other.m_passwordHash)  { }

	// 5. CONSTRUCTOR DE MOVIMIENTO
  /**
   * @brief Constructor de movimiento (C++11).
   * @note Optimiza cuando un User temporal es movido.
   */
  User(User&& other) noexcept
    : m_username(std::move(other.m_username)),
			m_email(std::move(other.m_email)),
			m_passwordHash(std::move(other.m_passwordHash)) {
    // Estado seguro para el objeto movido
    other.m_username = "moved_user";
    other.m_email = "moved_email";
    other.m_passwordHash = "moved_hash";
  }

	~User() = default;

private:
	bool IsValidEmail(const std::string& e) const {
		return e.find('@') != std::string::npos;
	}

	std::string HashPassword(const std::string& pass) const {
		return "HASH_" + pass;
	}

public:
	// Métodos de la clase (getters/setters)
	const std::string& GetUsername() const { return m_username; }
	const std::string& GetEmail() const { return m_email; }

	void SetEmail(const std::string& mail) {
		if (IsValidEmail(mail))
			m_email = mail;
	}

	void ChangePassword(const std::string& newPass) {
		if (newPass.size() >= 4)
			m_passwordHash = HashPassword(newPass);
	}

	void PrintInfo() const {
		std::cout << "User: " << m_username << " | Email: " << m_email << "\n";
	}

private:
	std::string m_username;
	std::string m_email;
	std::string m_passwordHash;

};
