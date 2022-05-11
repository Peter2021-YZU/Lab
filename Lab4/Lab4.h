#ifndef Lab4_h
#define Lab4_h


class Queue
{
private:
    int Size;
    int* intQueue;
    int front;
    int rear;
    int count;

public:
    Queue( int = 10 );
    ~Queue();
    void enqueue(int);
    int dequeue();
    int peek();
    int getCount();
    int getSize();
    bool isEmpty();
    bool isFull();
    void clearQueue();
    void printQueue();
};


#endif // Lab4
