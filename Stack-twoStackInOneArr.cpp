#include <bits/stdc++.h> 
class TwoStack {

public:

    // Initialize TwoStack.
    int *arr;
    int st;
    int e;
    int size;
    
    TwoStack(int s) {
        // Write your code here.
        arr = new int[s];
        st = -1;
        e = s;
        size = s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(e-st > 1){
          st++;
          arr[st] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if(e-st > 1){
          e--;
          arr[e] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(st > -1){
          int temp = arr[st];
          st--;
          return temp;
        }
        return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(e < size){
          int temp = arr[e];
          e++;
          return temp;
        }
        return -1;
    }
};
