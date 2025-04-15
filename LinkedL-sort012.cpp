/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    Node* zeroH = new Node(-1);
    Node* zeroT = zeroH;
    
    Node* oneH = new Node(-1);
    Node* oneT = oneH;
    
    Node* twoH = new Node(-1);
    Node* twoT = twoH;

    Node* curr = head;
    Node* prev = NULL;
    
    while(curr != NULL){
        if(curr->data == 0){
            prev = curr;
            curr = curr->next;
            prev->next = NULL;
            zeroT->next = prev;
            zeroT = zeroT->next;
        }
        else if(curr->data == 1){
            prev = curr;
            curr = curr->next;
            prev->next = NULL;
            oneT->next = prev;
            oneT = oneT->next;
        }
        else if(curr->data == 2){
            prev = curr;
            curr = curr->next;
            prev->next = NULL;
            twoT->next = prev;
            twoT = twoT->next;
        }
    }

    head = zeroH->next;
    zeroH->next = NULL;
    zeroT->next = oneH->next;
    oneH->next = NULL;
    oneT->next = twoH->next;
    twoH->next = NULL;
        
    return head;

    
}