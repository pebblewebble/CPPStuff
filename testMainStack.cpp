#include "lab9-stackLinkedImpl.h"
#include "lab9-stackArrayImpl.h"

int main(){
    MyStackLinked myStack;
    myStack.push(10);
    myStack.push(50);
    cout<<myStack.peek()<<endl;
    cout<<"\n\nArray Stack"<<endl;
    MyStackArr mySecondStack;
    mySecondStack.push(10);
    mySecondStack.push(50);
    mySecondStack.pop();
    mySecondStack.show();
}