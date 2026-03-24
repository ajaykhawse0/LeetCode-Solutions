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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*dummy = new ListNode(0,head);
        ListNode*prev =dummy,*curr=head;
        
        while(curr){
            ListNode*nextNode = curr->next;
            if(nextNode && curr->val == nextNode->val){
                
                while(nextNode && curr->val == nextNode->val){
                   
                    ListNode*temp=nextNode->next;
                    delete nextNode;
                    nextNode =temp;
                }
                 }

                 if(curr->next==nextNode){
                    prev=curr;
                 }
                 else{
                    prev->next=nextNode;
                    delete curr;
                 }
                 curr=nextNode;

        }
    return dummy->next;}
};