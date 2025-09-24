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
        ListNode* finalNode = new ListNode();
        ListNode* copy = finalNode;
        int carryover=0;
        while(l1!=NULL || l2!=NULL) {
            int sum = 0;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            sum += carryover;
            int remainder = sum%10;
            carryover = sum/10;
            finalNode->val = remainder;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            if (l1 != NULL || l2 != NULL || carryover != 0) {
                finalNode->next = new ListNode();
                finalNode = finalNode->next;
            }
            
        }

        while(carryover) {
            finalNode->val = carryover%10;
            if(carryover/10 == 0) break;
            finalNode->next = new ListNode();
            carryover /= 10;
        }
        return copy;
    }
};