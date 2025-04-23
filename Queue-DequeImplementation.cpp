#include <bits/stdc++.h> 
class Deque
{
public:
    // Initialize your data structure.
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int n)
    {
        // Write your code here.
        front = rear = -1;
        size = n;
        arr = new int[size];
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        bool flag;

        if(front == -1){
            front = rear = 0;
            arr[front] = x;
            flag = 1;
        }

        else if(front==0 && rear!=(size-1)){
            front = size-1;
            arr[front] = x;
            flag = 1;
        }

        else if(rear==(front-1) || (front==0 && rear==(size-1))){
            flag = 0;
        }

        else{
            front--;
            arr[front] = x;
            flag = 1;
        }

        return flag;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        bool flag;

        if(rear == -1){
            front = rear = 0;
            arr[rear] = x;
            flag = 1;
        }

        else if(front!=0 && rear==(size-1)){
            rear = 0;
            arr[rear] = x;
            flag = 1;
        }

        else if(rear==(front-1) || (front==0 && rear==(size-1))){
            flag = 0;
        }

        else{
            rear++;
            arr[rear] = x;
            flag = 1;
        }
        
        return flag;

    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        int x;
        if(front == -1){
            x = -1;
        }

        else if(front == rear){
            x = arr[front];
            front = rear = -1;
        }

        else if(front == size-1){
            x = arr[front];
            front = 0;
        }

        else{
            x = arr[front];
            front++;
        }

        return x;

    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        int x;

        if(rear == -1){
            x = -1;
        }

        else if(front == rear){
            x = arr[rear];
            front = rear = -1;
        }

        else if(rear == 0){
            x = arr[rear];
            rear = size-1;
        }

        else{
            x = arr[rear];
            rear--;
        }
        return x;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(front == -1){
            return -1;
        }

        else{
            return arr[front];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(rear == -1){
            return -1;
        }

        else{
            return arr[rear];
        }
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front == -1){
            return 1;
        }
        else{
            return 0;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if(rear==(front-1) || (front==0 && rear==(size-1))){
            return 1;
        }

        else{
            return 0;
        }
    }
};