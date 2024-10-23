#include "lab10-queueLinkedImpl.h"
int main(){
    QueueLinked test;
    // test.enqueue(5);
    // test.enqueue(11);
    // test.enqueue(34);
    // test.enqueue(67);
    // test.enqueue(43);
    // test.enqueue(55);
    // test.show();
    // test.moveNthFront(3);
    // test.show();
    QueueLinked Q1;
    QueueLinked Q2;
    QueueLinked Q3;
    Q1.enqueue(34); Q1.enqueue(22);
    Q1.enqueue(44); Q2.enqueue(10);
    Q2.enqueue(35); Q2.enqueue(38);
    Q2.enqueue(19); Q3.enqueue(Q2.dequeue());
    Q3.enqueue(Q2.dequeue()); Q3.enqueue(Q1.dequeue());
    Q2.enqueue(66);
    cout << Q1.sum() << ", " << Q2. sum() << ", " << Q3. sum() << "." << endl;
}