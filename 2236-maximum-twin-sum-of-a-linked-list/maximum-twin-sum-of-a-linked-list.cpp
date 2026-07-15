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
    int pairSum(ListNode* head) {
    //simply we have to add first and last node values while decreaing the right pointer and increasing the left one

    //brute force
    vector<int>arr;
    ListNode*temp = head;
    while(temp){
        arr.push_back(temp->val);
        temp = temp->next;
    }    
    int l = 0;
    int r = arr.size()-1;
    int ans = 0;

    while(l<r){
        ans = max(ans,arr[l]+arr[r]);
        l++;
        r--;
    }
    return ans;


    }
};