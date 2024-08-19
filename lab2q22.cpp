#include <iostream>
using namespace std;

string reverseString(string text);
bool compareString(string text, string text2);

int main(){
  string text;
  cout<<"Enter a string : ";
  cin>>text;

  string reversedText = reverseString(text);
  cout<<"Reverse entered string: "<< reversedText<<endl;

  if(compareString(string text, string text2)){
    cout<<"The entered string is a palindrome!"<<endl;
  }
}
