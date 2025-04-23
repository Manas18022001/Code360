#include <bits/stdc++.h> 
class Queue {
public:

    int qfront;
    int rear;
    int size;
    int *arr;
    Queue() {
        // Implement the Constructor
        qfront = -1;
        rear = -1;
        size = 100001;
        arr = new int[size];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == -1){
            return 1;
        }

        return 0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == size-1){
            cout<<"queue is full";
        }
        
        else if(rear == -1){
            qfront = 0;
            rear = 0;
            arr[rear] = data;
        }

        else{
            rear++;
            arr[rear] = data;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront == -1){
            return -1;
        }
        
        else if(qfront == rear){
            int x = arr[qfront];
            qfront = rear = -1;
            return x;
        }
        
        else{
            int x = arr[qfront];
            qfront ++;
            return x;
        }
    }

    int front() {
        // Implement the front() function
        if(qfront == -1){
            return -1;
        }

        return arr[qfront];
    }
};