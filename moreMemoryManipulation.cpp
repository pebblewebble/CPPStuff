#include <iostream>

using namespace std;

int main() {
  double dd;
  /** Memory Allocation */
  double *d = new double;
  *d = 10.9;
  cout << "d = " << *d;
  cout << "; Address of d = " << &d;

  /** Memory Deallocation */
  delete d;

  cout << "\nProgram Ended!" << endl;
  return 0;
}
