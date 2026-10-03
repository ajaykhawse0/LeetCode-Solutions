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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1)return head;
        vector<int>arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        int l = 0;
        int n = arr.size();
        while(n-l>=k){
            reverse(arr.begin()+l,arr.begin()+l+k);
            l+=k;
        }
        head = new ListNode(arr[0]);
        ListNode* temp = head;
        for(int i=1;i<n;i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }

        return head;
    }
};