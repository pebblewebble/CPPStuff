#include <iostream>

using namespace std;

int main() {
  double dd;
  /** Memory Allocation */
  double *d = new double;

  /** Memory Deallocation */
  delete d;

  cout << "\nProgram Ended!" << endl;
}
