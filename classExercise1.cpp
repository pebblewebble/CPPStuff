#include <iostream>
using namespace std;

int main() {
  int feet, inch;
  cout << "Enter Feet:";
  cin >> feet;
  cout<< "Enter Inch:";
  cin>>inch;
  double centimeter=((feet*12)+inch)*2.54;
  cout<<centimeter;
  return 0;
}
