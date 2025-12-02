/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;

        Node* head = root;
        while(head!=NULL){
            Node* dummy=new Node(0);
            Node* tail = dummy;
            while(head!=NULL) {
                if(head->left!=NULL){
                    tail->next = head->left;
                    tail = tail->next;
                }

                if(head->right!=NULL){
                    tail->next = head->right;
                    tail = tail->next;
                }
                head = head->next;
            }
            head = dummy->next;
        }
        return root;
    }
};