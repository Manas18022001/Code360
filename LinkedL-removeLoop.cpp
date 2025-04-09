/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node *removeLoop(Node *head)
{
    // Write your code here.
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while(slow!=NULL && fast!=NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast!=NULL)
            fast = fast->next;
        
        if(slow == fast)
            break;
    }

    if(slow == NULL || fast == NULL){
        return head;
    }

    slow = head;

    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    while(slow->next != fast){
        slow = slow->next;
    }

    slow->next = NULL;

    return head;

}