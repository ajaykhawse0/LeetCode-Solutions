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
    ListNode* rotateRight(ListNode* head, int k) {

        if(k==0 || !head || !head->next)return head;
        int length =1;
        ListNode*curr=head;
        while(curr->next){
            curr=curr->next;
            length++;
        }
       k = k%length;
        
        if(k==0)return head;
        
        ListNode*slow=head;
        ListNode*fast=head;

        //go to n-k position for 1,2,3,4,5 it will be at 3
        while(k--){
            fast=fast->next;
        }
        
        //move to one position back from neew Head using slow ptr and to the end of rated portion using fast ptr
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode*newHead = slow->next;
        slow->next=nullptr;
        fast->next=head;

        return newHead;

    }
};