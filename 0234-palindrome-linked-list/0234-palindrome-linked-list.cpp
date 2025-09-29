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
private:   
    ListNode* reverseFun(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* front = temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        //find middle
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //now reverse slow->next
        ListNode* reversedList = reverseFun(slow->next);
        ListNode* second= reversedList;
        while(second!=NULL) {
            cout<<second->val<<endl;
            if(second->val != temp->val) {
                reverseFun(slow->next);
                return false;
            }
            second = second->next;
            temp = temp->next;
        }
        reverseFun(slow->next);
        return true;
    }
};