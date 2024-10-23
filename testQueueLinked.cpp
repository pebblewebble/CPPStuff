#include "lab10-queueLinkedImpl.h"
int main(){
    QueueLinked test;
    test.enqueue(5);
    test.enqueue(11);
    test.enqueue(34);
    test.enqueue(67);
    test.enqueue(43);
    test.enqueue(55);
    test.show();
    test.moveNthFront(3);
    test.show();
}