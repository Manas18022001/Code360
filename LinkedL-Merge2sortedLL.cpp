#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* solve(Node<int>* first, Node<int>* second){
    Node<int> *curr1 = first;
    Node<int> *nex1 = first->next;
    Node<int> *curr2 = second;
    Node<int> *nex2 = second->next;

    if(first->next == NULL && second->next == NULL){
        first->next = second;
        return first;
    }
    while(nex1!=NULL && curr2!=NULL){
        if((curr2->data >= curr1->data) && (curr2->data <= nex1->data)){
            curr1->next = curr2;
            nex2 = curr2->next;
            curr2->next = nex1;
            curr1 = curr2;
            curr2 = nex2;
            
        }
        else{
            curr1 = nex1;
            nex1 = nex1->next;

            if(nex1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;

}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL || (first == NULL && second == NULL))
        return second;
    
    if(second == NULL)
        return first;
    
    if(first->data < second->data)
        return solve(first, second);
    
    else
        return solve(second, first);
}
