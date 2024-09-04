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
  cout << "\nProgram ended!"<<endl;
  return 0;
}
