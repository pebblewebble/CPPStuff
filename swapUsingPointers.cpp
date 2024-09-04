#include <iostream>

using namespace std;

void swap(int *value1, int *value2);

int main() {
  int num1, num2;
  cout << "Enter two nums :";
  cin >> num1;
  cin >> num2;
  int *ptr1, *ptr2;
  ptr1 = &num1;
  ptr2 = &num2;
  cout<<endl;
  cout << "Before swapping in main function :";
  cout<<endl;
  cout << " Value of num1 = " << num1;
  cout << " Value of num2 = " << num2;
  cout<<endl;
  swap(ptr1, ptr2);
  cout << "After swapping in main function :";
  cout<<endl;
  cout << " Value of num1 = " << *ptr1;
  cout << " Value of num2 = " << *ptr2;
  cout<<endl;
}

void swap(int *value1, int *value2) {
  *value1 = *value1 + *value2;
  *value2 = *value1 - *value2;
  *value1 = *value1 - *value2;
}
