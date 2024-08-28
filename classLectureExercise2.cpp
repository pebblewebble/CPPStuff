#include<iostream>
using namespace std;
class cashRegister{
  private:
    int cashOnHand=500;
public:
  void update(){
    int amount;
    cout<<"Please enter an amount: ";
    cin>>amount;
    cashOnHand+=amount;
  }
  int getBalance(){
    return this->cashOnHand;
  }
};

int main(){
  cashRegister myRegister;
  cout<<"Current balance"<<endl;
  cout<<myRegister.getBalance()<<endl;
  cout<<"After Update"<<endl;
  myRegister.update();
  cout<<myRegister.getBalance();
}
