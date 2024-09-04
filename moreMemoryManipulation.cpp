#include <iostream>

using namespace std;

int main() {
  /** Memory Allocation */
  double *d = new double;

  /** Memory Deallocation */
  delete d;

  cout << "\nProgram Ended!" << endl;
}
