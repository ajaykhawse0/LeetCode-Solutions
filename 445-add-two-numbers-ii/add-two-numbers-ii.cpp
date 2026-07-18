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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> arr1;
        vector<int> arr2;

        ListNode* temp = l1;
        while (temp) {
            arr1.push_back(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while (temp) {
            arr2.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr1.size();
        int m = arr2.size();
        int i = n - 1;
        int j = m - 1;
        int sz = max(n, m);
        vector<int> ans(sz, 0);
        int k = sz - 1;
        int carry = 0;
        while (k >= 0 && i >= 0 && j >= 0) {
            int val = arr1[i] + arr2[j] + carry;
            ans[k] = val % 10;
            carry = val / 10;
            k--;
            i--;
            j--;
        }

        while (k >= 0 && i >= 0) {
            int val = arr1[i] + carry;
            ans[k] = val % 10;
            carry = val / 10;
            k--;
            i--;
        }
        while (k >= 0 && j >= 0) {
            int val = arr2[j] + carry;
            ans[k] = val % 10;
            carry = val / 10;
            k--;
            j--;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp1 = dummy;

        if (carry) {
            temp1->next = new ListNode(carry);
            temp1 = temp1->next;
        }

        for (int i = 0; i < sz; i++) {
            temp1->next = new ListNode(ans[i]);
            temp1 = temp1->next;
        }

        return dummy->next;


    }
};