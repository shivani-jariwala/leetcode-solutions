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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        int sum =0, carry=0;
        while(l1!=NULL || l2!=NULL) {
            // sum = l1->val + l2->val + carry; // this is wrong bcoz in while we used or condition so either of them can be null;
            sum=carry;// this is correct bcoz everytime we add, from the previous we just want to bring back the carry and not the sum... therefore sum = sum + carry is incorrect.
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            // sum += carry;
            carry = sum/10; 
            ListNode* newNode = new ListNode(sum%10);
            curr->next = newNode;
            curr = curr->next;
            //in the following 2 lines we used if check bcoz if l1 and l2 have uneven lengths than we don't know which one is null and therefore we put a check to both
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(carry) {
            curr->next = new ListNode(carry);
        }
        return dummyNode->next;
        
    }
};