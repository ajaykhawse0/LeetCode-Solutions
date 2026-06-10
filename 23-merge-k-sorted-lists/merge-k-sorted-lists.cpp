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
        ListNode*temp =  dummy;

        priority_queue<int,vector<int>,greater<int>>minHeap;

        for(ListNode*list:lists){
            ListNode*curr=list;
            while(curr){
                minHeap.push(curr->val);
                curr=curr->next;
            }
        }

        while(!minHeap.empty()){
            ListNode*node = new ListNode(minHeap.top());
            minHeap.pop();
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }

};