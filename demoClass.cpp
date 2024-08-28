#include <iostream>

using namespace std;

class BankAccount {
private:
  double balance;

public:
  // double getBalance() { return this->balance; }
  // void setBalance(double bal) { this->balance = bal; }
  double getBalance();
  void setBalance(double bal);
};

int main() {
  cout << "--- demo.cpp ---" << endl;
  BankAccount myAccount;
  cout << myAccount.getBalance();
  cout << "\nProgram ended!" << endl;
  return 0;
}

//We can determine the body of a method later by using this method below
double BankAccount ::getBalance(){
  return this->balance;
}
