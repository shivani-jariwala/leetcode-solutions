/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* iter = head;
        while(iter!=NULL) {
            Node* copy = new Node(iter->val);
            copy->next = iter->next;
            iter->next = copy;
            iter= iter->next->next;
        }
        iter=head;
        while(iter!=NULL) {
            if(iter->random!=NULL) {
                iter->next->random = iter->random->next;
            }
            iter=iter->next->next;
        }
        iter=head;
        Node* dummyNode = new Node(0);
        Node* copyIter = dummyNode;
        while(iter!=NULL) {
            Node* front = iter->next->next;
            copyIter->next = iter->next;
            copyIter = copyIter->next;
            iter->next = front;
            iter=front;
        }
        return dummyNode->next;
    }
};