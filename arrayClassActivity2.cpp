#include <iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter how many value you want to store:";
    cin>>num;
    int *dynamicArray;
    dynamicArray=new int[num];
    for(int i =0;i<num;i++){
        cout<<"Enter value's "<<i+1<<": ";
        cin>>dynamicArray[i];
    }
    int sum=0;
    int currMin=dynamicArray[0];
    int currMax=0;
    for(int i =0;i<num;i++){
        if(i!=0){
            cout<<" + ";
        }
        if(currMin>dynamicArray[i]){
            currMin=dynamicArray[i];
        }
        if(currMax<dynamicArray[i]){
            currMax=dynamicArray[i];
        }
        cout<<dynamicArray[i];
        sum+=dynamicArray[i];
    }
    cout<<" = "<<sum;
    cout<<endl;
    cout<<"Min:"<<currMin<<endl;
    cout<<"Max:"<<currMax;
}