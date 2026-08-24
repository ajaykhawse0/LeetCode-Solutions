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
        ListNode*dummy = new ListNode(0);
        ListNode*newHead = dummy;

        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto list:lists){
            auto curr = list;
            while(curr){
                pq.push(curr->val);
                curr = curr->next;
            }
        }

        while(!pq.empty()){
            ListNode*node =  new ListNode(pq.top());
            pq.pop();
            newHead->next = node;
            newHead = newHead->next; 
        }

        return dummy->next;
    }
};