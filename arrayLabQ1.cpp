#include<iostream>
using namespace std;


int main(){
  int myArray[10]={};
  int len = sizeof(myArray)/sizeof(myArray[0]);
  for(int i =0;i<len;i++){
    cout<<"Enter value "<<i+1<<": "; 
    cin>>myArray[i];
  }
}
