#pragma once
#include "Prerequisites.h"
#include "BankAccount.h"


class 
Bank {
public:
	Bank()  = default;
	~Bank() = default;

	void AddAccount(const std::string& ownerName, double initialBalance) {
		std::string accountId = "CTA-" + std::to_string(++m_idCounter);
		BankAccount newAccount(ownerName, accountId, initialBalance);
		m_accounts.push_back(newAccount);
	}

	void AddAccount(const BankAccount& account) {
		m_accounts.push_back(account);
	}

	BankAccount* FindAccountById(const std::string& accountId) {
		for (auto& account : m_accounts) {
			if (account.GetAccountId() == accountId) {
				return &account;
			}
		}
		return nullptr; // No se encontró la cuenta
	}

	void PrintAllAccounts() const {
		for (const auto& account : m_accounts) {
			account.PrintSummary();
		}
	}

private:
	std::vector<BankAccount> m_accounts;
	int m_idCounter;
};