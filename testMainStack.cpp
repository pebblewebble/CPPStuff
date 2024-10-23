#include "lab9-stackLinkedImpl.h"
#include "lab9-stackArrayImpl.h"

int main(){
    MyStackLinked myStack;
    string equation;
    bool correct=true;
    cout<<"Enter your equation here:"<<endl;
    cin>>equation;
    for(char c:equation){
        if(c=='('){
            myStack.push("(");
        }else if(c==')'){
            if(myStack.peek()=="("){
                myStack.pop();
            }else{
                correct=false;
            }
        }
    }
    if(myStack.isEmpty()&&correct){
        cout<<"The parenthesis of the equation is balance.";
    }else{
        cout<<"The parenthesis of the equation is not balanced.";
    } 
}