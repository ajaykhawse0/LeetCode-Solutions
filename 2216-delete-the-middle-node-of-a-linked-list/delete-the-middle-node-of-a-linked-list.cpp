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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL|| head->next==NULL){
            return NULL;
        }
        //slow fast approach
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow){
        prev->next = slow->next;}
        else{
          prev->next = nullptr;
        }
        delete slow;

        return head;

    }
};