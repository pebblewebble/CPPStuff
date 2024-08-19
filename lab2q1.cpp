#include <iostream>
#include "mymath.h"

using namespace mymath;
using namespace std;

// FUNCTION PROTOTYPE
// int add(int,int);

int main(){
    cout<<"Enter two integers: ";
    int firstNum;
    cin>>firstNum;
    int secondNum;
    cin>>secondNum;
    cout<<"Sum = "<<add(firstNum,secondNum)<<endl;
    return 0;
}

//FUNCTION DEFINITION
// int add(int a, int b){
//     return a+b;
// }