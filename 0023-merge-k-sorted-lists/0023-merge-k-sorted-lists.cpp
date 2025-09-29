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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        //do priority queue, we will store val, ListNode
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        for(int i=0; i<lists.size(); i++) {
            if(lists[i]) pq.push({lists[i]->val, lists[i]}); //if head exists then only add
        }
        while(!pq.empty()){
            //get min from pq
            auto it = pq.top();
            pq.pop();
            temp->next=it.second;
            //now insert the next eligible node
            if(it.second->next) pq.push({it.second->next->val, it.second->next});
            //it.second bcoz it->next is wrong since "it" is a pair and not a node
            temp = temp->next;
        }
        return dummyNode->next;
    }
};