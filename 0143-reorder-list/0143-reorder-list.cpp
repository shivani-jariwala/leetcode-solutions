/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
       if(head==NULL) return;
       //find the middle 
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast!=NULL && fast->next!=NULL)  {
        slow = slow->next;
        fast = fast->next->next;
       }
       //now reverse everything after slow->next
       ListNode* rev = slow->next;
       slow->next = NULL;
       ListNode* prev = NULL;

       while(rev!=NULL) {
        ListNode* temp = rev->next;
        rev->next = prev;
        prev = rev;
        rev = temp;
       }

       //[1,2,3]
       //[5,4]
       ListNode* first = head;
       ListNode* second = prev;
       //always second <= first;
       while(second!=NULL){
        ListNode* next1 = first->next;
        ListNode* next2 = second->next;
        first->next = second;
        second->next = next1;
        first = next1;
        second = next2;
       }

    }
};