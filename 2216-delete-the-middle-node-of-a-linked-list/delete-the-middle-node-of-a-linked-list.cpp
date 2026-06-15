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
        int len =0;
        auto temp = head;

        while(temp){
            len++;
            temp=temp->next;
        }
        if(len==1)return NULL;
        int mid = len/2 + 1;
         temp=head;
         ListNode* prev = nullptr;
        for(int i=0;i<mid-1;i++){
               prev=temp;
               temp=temp->next;
        }
        //
        prev->next = temp->next;
        delete temp;

        return head;
        
    }
};