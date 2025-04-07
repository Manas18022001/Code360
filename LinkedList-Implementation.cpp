/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node *next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    
    ~Node(){
        int value = this->data;
        
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        
        cout<< "The memory is free for node "<< value;
    }
    
};

void insertAtHead(Node* &head, int data){
    Node *temp = new Node(data);
    
    temp->next = head;
    head = temp;
}
void insertAtTail(Node* &tail, int data){
    Node *temp = new Node(data);
    
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, int position, int data){
    int count = 1;
    Node* curr = new Node(data);
    curr->next = head;
    
    if(position == 1 ){
        head = curr;
        return;
    }
    Node *temp = head;
    while(count < position-1){
        temp = temp->next;
        count++;
    }  
    curr->next = temp->next;
    temp->next = curr;
    
}

void print(Node* &head){
    Node *temp = head;
    
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


int main()
{
    Node *Node1 = new Node(5);
    
    Node *head = Node1;
    Node *tail = Node1;
    
    insertAtHead(head, 4);
    insertAtTail(tail, 6);
    insertAtPosition(head, 1, 8);
    print(head);
    return 0;
}