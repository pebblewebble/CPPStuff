#include <iostream>

using namespace std;
void changeMe(int &value) { value = value * 2; }

int main() {
  int n = 10;
  changeMe(n);
  cout << "n = " << n << endl;

  cout << endl;
  return 0;
}
