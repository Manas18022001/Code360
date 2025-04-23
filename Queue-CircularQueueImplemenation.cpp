#include <bits/stdc++.h> 
class CircularQueue{
    public:
    // Initialize your data structure.
    int *arr;
    int front;
    int rear;
    int size;
    CircularQueue(int n){
        // Write your code here.
        front = rear = -1;
        size = n;
        arr = new int[size];
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        bool flag;
        if(rear == -1){
            front = rear = 0;
            arr[rear] = value;
            flag = 1;
        }

        else if(rear==size-1 && front!=0){
            rear = 0;
            arr[rear] = value;
            flag = 1;

        }

        else if((rear==(front-1) || (rear==(size-1) && front==0))){
            flag = 0;
        }

        else{
            rear++;
            arr[rear] = value;
            flag = 1;
        }

        return flag;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(front == -1){
            return -1;
        }

        else if(rear == front){
            int x = arr[front];
            rear = front = -1;
            return x;
        }

        else if(front == size-1){
            int x = arr[front];
            front = 0;
            return x;
        }

        else{
            int x = arr[front];
            front++;
            return x;
        }
    }
};