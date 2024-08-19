#include <iostream>
using namespace std;

void RecursiveReverseDisplayNumber(int n1, int n2) {
//   for (int i = n2; i > n1 - 1; i--) {
//     if (i != n2) {
//       cout << " + ";
//     }
//     cout << i;
//   }
//   cout << " = ";
    if(n2>n1){
        cout<<n2<<" + ";
        RecursiveReverseDisplayNumber(n1, n2-1);
    }
    else{
        cout<<n2<<" ";
    }
}
int RecursiveCalSum(int n1, int n2) {
//   int sum = 0;
//   for (int i = n2; i > n1 - 1; i--) {
//     sum += i;
//   }
//   return sum;
    if(n2>n1){
        return n2+RecursiveCalSum(n1,n2-1);
    }
}
int main() {
  int startvalue, endvalue;
  cout << "Enter a start value: ";
  cin >> startvalue;
  cout << "Enter a end value: ";
  cin >> endvalue;
  cout << endl;
  RecursiveReverseDisplayNumber(startvalue, endvalue);
  cout << RecursiveCalSum(startvalue, endvalue);
  return 0;
}
