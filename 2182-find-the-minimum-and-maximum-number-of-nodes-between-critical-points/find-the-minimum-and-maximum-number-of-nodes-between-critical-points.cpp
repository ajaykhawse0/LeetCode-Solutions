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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>allCritical;
        int prev = 0;

        ListNode*temp = head;
        int len = 1;
        while(temp->next){
           if(prev==0){
            prev = temp->val;
            
           }
           else{
            if(temp->val>prev && temp->val>temp->next->val){
                allCritical.push_back(len);
            }
           else  if(temp->val<prev && temp->val<temp->next->val){
                allCritical.push_back(len);
            }
            prev = temp->val;
           }

           temp = temp->next;
           len++;
        }
        vector<int>ans(2,-1);
        if(allCritical.size()<2)return ans;
        ans[1] = allCritical[allCritical.size()-1]-allCritical[0];

        for(int i=1;i<allCritical.size();i++){
           if(ans[0]==-1){
            ans[0] = allCritical[i] - allCritical[i-1];
           }
           else{
             ans[0] = min(ans[0],allCritical[i] - allCritical[i-1]);
           }
        }



  return ans;  }
};