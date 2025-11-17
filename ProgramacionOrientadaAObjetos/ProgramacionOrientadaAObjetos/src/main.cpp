#include "Prerequisites.h"
#include "BankAccount.h"

int main() {
  BankAccount a("Roberto", "CTA-001", 1000.0);
  BankAccount b("Ana", "CTA-002", 500.0);

  a.Deposit(250.0);        // Roberto recibe dinero
  a.Withdraw(100.0);       // Paga algo
  a.TransferTo(b, 300.0);  // Le transfiere a Ana

  a.PrintSummary();
  b.PrintSummary();

  return 0;
}
