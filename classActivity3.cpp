#include <iostream>
using namespace std;
int main() {
  int number = 100;

  for (int i = number; i > 10; i -= 5) {
    cout << i << endl;
  }
  do {
    cout << number << endl;
    number -= 5;
  } while (number > 10);
}
