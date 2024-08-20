#include <iostream>
using namespace std;

int sumArray(int arrayToBeSum[], int len){
  int sum=0;
  // int len=sizeof(arrayToBeSum)/sizeof(arrayToBeSum[0]);
  for(int i =0;i<len;i++){
    sum+=arrayToBeSum[i];
  }
  return sum;
}

int main(){
  int billy[]={16,2,77,40,12071,51};
  int len = sizeof(billy)/sizeof(billy[0]);
  cout<<sumArray(billy,len)<<endl;
  return 0;
}