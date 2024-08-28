#include <string>
#include <iostream>
using namespace std;
class BankAccount {
private:
  double balance;
  double interest_rate;

public:
  void set(int dollars, int cents);
  void update();
  double get_balance();
  double get_rate();
  void set_rate(int rate);
};

void BankAccount ::set(int dollars, int cents){
  this->balance=stod(to_string(dollars)+"."+to_string(cents));
}

void BankAccount ::update(){
  this->balance+=this->balance*(this->interest_rate)/100;
}

double BankAccount ::get_balance(){
  return this->balance;
}

double BankAccount ::get_rate(){
  return this->interest_rate;
}

void BankAccount ::set_rate(int rate){
  this->interest_rate=rate;
}

int main(){
  BankAccount myAccount;
  myAccount.set_rate(5);
  myAccount.set(50,15);
  cout<<myAccount.get_rate()<<endl;
  cout<<myAccount.get_balance()<<endl;
  myAccount.update();
  cout<<"Account Balance after update"<<endl;
  cout<<myAccount.get_balance()<<endl;
}











