#include "MyStack.h"
#include "MyQueue.h"
#include "MyQueue.cpp"
#include "MyStack.cpp"
#include <iostream>
using namespace std;

int main(){
    MyStack ms;
    MyQueue mq;
    for (int i = 0; i < 100; i++)
    {
        ms.push(i+1);
        mq.enqueue(i+1);

    }

    while (!ms.isEmpty())
    {
        cout << ms.top() << ",";

        ms.pop();

    }
    cout << endl;

    while (!mq.isEmpty())
    {
        cout << mq.peek() << ",";

        mq.dequeue();

    }
    
    return 0;
}