/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

// Node * removeDuplicates(Node *head)
// {
//     if(head == NULL || head->next == NULL)
//         return head;

//     Node* curr = head;

//     while( curr->next != NULL){
//         if(curr->data != curr->next->data)
//             curr = curr->next;
//         else{
//             Node* nex = curr->next;
//             curr->next = nex->next;
//             nex->next = NULL;
//             delete nex;
//         }
//     }
//     return head;
// }
Node * removeDuplicates(Node * head) {
    if(head==NULL || head->next==NULL)
    return head;
    
    Node* curr = head;
    Node* fwd = curr->next;
    while(fwd!=NULL)
    {
        if(curr->data==fwd->data)
        {
        curr->next=fwd->next;
        fwd->next=NULL;
        fwd = curr->next;
        }
        else
        {
        curr=curr->next;
        fwd=curr->next;
        }
    }
    return head;
}
