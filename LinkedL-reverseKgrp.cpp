/*
        Time Complexity: O(n)
        Space Complexity: O(n)

        Where 'n' is the number of nodes in the Linked list.
*/

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

int lengthOfLinkedList(Node * &head)
{
    Node * temp = head;
    int length = 0;
    while(temp)
    {
        length++;
        temp = temp -> next;
    }
    return length;
}
Node* kReverse(Node* head, int k) {
    // Write your code here.
    int length = lengthOfLinkedList(head);
    if(head == NULL || k > length)
        return head;
    Node * nextNode = NULL;
    Node * currentNode = head;
    Node * previousNode = NULL;
    int count = 1;
    while(currentNode && count <= k)
    {
        nextNode = currentNode -> next;
        currentNode -> next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
        count++;
    }
    if(nextNode)
        head -> next = kReverse(nextNode, k);
    return previousNode;
}