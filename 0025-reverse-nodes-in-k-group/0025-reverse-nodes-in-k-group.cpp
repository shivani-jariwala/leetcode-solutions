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
    ListNode* findKthNode(ListNode* head, int k) {
        k =k-1;
        while(head!=NULL && k>0){
            k--;
            head = head->next;
        }
        return head;
    }
    ListNode* reverseFun(ListNode* temp) {
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* first = temp->next;
            temp->next=prev;
            prev=temp;
            temp=first;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevLast = NULL;
        while(temp!=NULL) {
            ListNode* newHead = findKthNode(temp, k);
            if(newHead==NULL){
                prevLast->next = temp;
                break;
            }
            ListNode* nextNode = newHead->next;
            newHead->next = NULL;
            reverseFun(temp);
            if(temp==head){
                head=newHead;
            }else{
                prevLast->next = newHead;
            }
            prevLast=temp;
            temp=nextNode;
        }
        return head;
    }
};