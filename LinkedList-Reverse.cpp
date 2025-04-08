#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == NULL){
        return head;
    }

    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *nex = curr->next;

    while(curr != NULL){
        curr->next = prev;
        prev = curr;
        curr = nex;
        if(curr != NULL)
            nex = curr->next;
    }

    return prev;

}


//recursive approach
// #include <bits/stdc++.h>

// /****************************************************************

//     Following is the class structure of the LinkedListNode class:

//     template <typename T>
//     class LinkedListNode
//     {
//     public:
//         T data;
//         LinkedListNode<T> *next;
//         LinkedListNode(T data)
//         {
//             this->data = data;
//             this->next = NULL;
//         }
//     };

// *****************************************************************/
// LinkedListNode<int> * reverse(LinkedListNode<int> * &prev, LinkedListNode<int> * &curr){
//     if(curr == NULL){
//         return prev;
//     }
//     LinkedListNode<int> *nex = curr->next;
//     curr->next = prev;
//     reverse(curr, nex);
// }

// LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
// {
//     LinkedListNode<int> *prev = NULL;
//     LinkedListNode<int> *curr = head;
    
//     return reverse(prev, curr);
// }