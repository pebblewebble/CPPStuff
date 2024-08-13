#include <iostream>
using namespace std;
int main(){
    cout<<"Enter number of rows (for diamond (triangle) dimension) : ";
    int num;
    cin>>num;
    int starCounter=1;
    int space=num-1;
    for(int i = 0;i<num;i++){
       for (int j =0;j<space;j++){
        cout<<" ";
       } 
       for(int x =0;x<starCounter;x++){
        cout<<"*";
       } 
       starCounter=starCounter+2;
       space--;
       cout<<""<<endl;
    }
    space=1;
    for(int i=num;i!=0;i--){
        for(int j=0;j<space;j++){
            cout<<" ";
        }
        for(int x=starCounter-2;x!=0;x--){
            cout<<"*";
        }
        starCounter-=2;
        space+=1;
        cout<<""<<endl;
    }
    return 0;
}