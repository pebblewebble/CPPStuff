#include <iostream>
using namespace std;

int main() {
  /** VARIABLE */
  int i = 100;
  /** ACCESSING MEMORY ADDR */
  cout << "Value = " << i;
  cout << "; Memory Address = " << &i << endl;
  /** Pointer **/
  int *ptr;
  /** Assign memory address to pointer */
  ptr = &i;
  cout << "Value of ptr = " << ptr;
  cout << "; Dereference Value of *ptr =" << *ptr;
  cout << "; Memory Address of ptr =" << &ptr << endl;
  cout << "\nProgram ended!" << endl;
  return 0;
}
