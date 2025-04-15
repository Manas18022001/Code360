#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }

    unordered_map <int, bool> mp;
    Node *curr = head;
    Node *prev = NULL;

    while(curr != NULL){
        if(mp[curr->data] == true){
            prev->next = curr->next;
            curr->next = NULL;
            curr = prev->next;
        }

        else{
            mp[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }

    return head;

}