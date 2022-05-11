#include <iostream>
#include "Lab4.h"
using namespace std;


Queue::Queue( int sizeOfQueue )
{
    Size = sizeOfQueue;
    cout << "A queue of size " << Size << " is created\n";
}

void Queue::enqueue(int task)
{
    if( intQueue == NULL ){
        count = 0;
        intQueue = new int(Size);
        intQueue[count] = task;
        front = task;
        count++;
    }
    else{
        intQueue[count] = task;
        rear = task;
        count++;
    }
}
int Queue::dequeue()
{
    int tempFront = front;
    front = intQueue[1];
    for(int i = 0; i < count; ++i){
        intQueue[i] = intQueue[i+1];
    }
    count--;
    return tempFront;
}
int Queue::peek()
{
    return front;
}
int Queue::getCount()
{
    return count;
}
int Queue::getSize()
{
    return Size;
}
bool Queue::isEmpty()
{
    if( count == 0 ){
        return true;
    }
    else{
        return false;
    }
}
bool Queue::isFull()
{
    if( count > Size ){
        return true;
    }
    else{
        return false;
    }
}
void Queue::clearQueue()
{
    intQueue = 0;
    front = 0;
    rear = 0;
    count = 0;
}
void Queue::printQueue()
{
    for(int i = 0; i < count; ++i){
            cout << intQueue[i] << " ";
        }
    cout << endl;
}

Queue::~Queue()
{
    delete[] intQueue;
    cout << "A queue of size " << Size << " is deleted\n";
}

