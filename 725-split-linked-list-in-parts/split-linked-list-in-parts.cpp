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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode*temp = head;

        while(temp){
            len++;
            temp = temp->next;
        }
        int parts = 0;
        int extra = 0;
        if(len<k){
            parts = 1;
        }else{
            parts  = len/k;
            extra = len%k;
        }
        vector<ListNode*>ans;

        temp = head;
        ListNode*prev = nullptr;
        int j = 0;
        while(temp && j<k){
            
                ans.push_back(temp);
                int i=0;
                while(i<parts+(extra>0)){
                    prev = temp;
                    temp = temp->next;
                    i++;
                }
                prev->next = nullptr;//disconnection
                extra--;

                j++;


            }
    while(j<k){
        ans.push_back(nullptr);
        j++;
    }

    return ans;

        


    }
};