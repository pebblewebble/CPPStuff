#include <iostream>

using namespace std;

class BankAccount {
private:
  double balance;

public:
  // double getBalance() { return this->balance; }
  // void setBalance(double bal) { this->balance = bal; }
  BankAccount();
  ~BankAccount();
  double getBalance();
  void setBalance(double bal);
};

int main() {
  cout << "--- demo.cpp ---" << endl;
  BankAccount myAccount;
  myAccount.setBalance(1000);
  cout << myAccount.getBalance();
  cout << "\nProgram ended!" << endl;
  return 0;
}
BankAccount::BankAccount() {
  cout << "---Constructing BankAccount object" << endl;
}
BankAccount::~BankAccount() {
  cout << "---Deconstructing BankAccount object" << endl;
}
// We can determine the body of a method later by using this method below
double BankAccount ::getBalance() { return this->balance; }
void BankAccount ::setBalance(double bal) { this->balance = bal; }
