#include <algorithm>
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

  if(compareString(text, reversedText)){
    cout<<"The entered string is a palindrome!"<<endl;
  }
  else{
    cout<<"The entered string is NOT a palindrome!"<<endl;
  }
  return 0;
}

string reverseString(string text){
  reverse(text.begin(),text.end());
  return text;
}
