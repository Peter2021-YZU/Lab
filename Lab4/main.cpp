#include <iostream>
#include "Lab4.h"
using namespace std;



int main()
{
    int queueSize;
    int testCases;
    cin >> queueSize;
    Queue idealQueue(queueSize);
    Queue waitingQueue(queueSize);

    cin >> testCases;
    int counter = 0;
    while( counter < testCases ){
        idealQueue.clearQueue();
        waitingQueue.clearQueue();
        int numbSec = 0;
        int numbTask;
        int task;
        cin >> numbTask;
        for(int i = 0; i < numbTask; ++i){
            cin >> task;
            idealQueue.enqueue(task);
        }
        for(int i = 0; i < numbTask; ++i){
            cin >> task;
            waitingQueue.enqueue(task);
        }

        cout << "Test " << counter+1 << ": " << endl;
        while( (!waitingQueue.isEmpty()) && (!idealQueue.isEmpty()) ){
            if( idealQueue.peek() == waitingQueue.peek()){
                idealQueue.dequeue();
                waitingQueue.dequeue();
                numbSec += 2;
            }
            else{
                int curTask = waitingQueue.dequeue();
                waitingQueue.enqueue(curTask);
                numbSec += 1;
                waitingQueue.printQueue();
            }
        }
        cout << numbSec << endl;
        counter++;
    }
    return 0;
}
