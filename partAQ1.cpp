#include <iostream>

using namespace std;

int main() {
  int num1, num2, sum;
  int *ptr1, *ptr2;
  cout << "Enter any two numbers :";
  cin >> num1;
  cin >> num2;
  ptr1 = &num1;
  ptr2 = &num2;
  cout << "Address of num1 = " << ptr1;
  cout << "; Value of num1 =" << *ptr1 << endl;
  cout << "Address of num2 = " << ptr2;
  cout << "; Value of num2 = " << *ptr2 << endl;
  sum = *ptr1 + *ptr2;
  cout << "Sum = " << sum;
}
