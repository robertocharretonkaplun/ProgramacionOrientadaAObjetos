#include "Prerequisites.h"
#include "BankAccount.h"
#include "Bank.h"
int main() {
  Bank Santander;

	Santander.AddAccount("Roberto", 1000.0);
	Santander.AddAccount("Maria", 1500.0);


  BankAccount Ana("Ana", "0x3f8000", 500.0);
	Santander.AddAccount(Ana);

	Santander.PrintAllAccounts();

  //BankAccount a("Roberto", "CTA-001", 1000.0);

  //a.Deposit(250.0);        // Roberto recibe dinero
  //a.Deposit(0);        // Roberto recibe dinero
  //a.Withdraw(100.0);       // Paga algo
  //a.TransferTo(b, 300.0);  // Le transfiere a Ana
  //
  //a.PrintSummary();
  //b.PrintSummary();

  return 0;
}
