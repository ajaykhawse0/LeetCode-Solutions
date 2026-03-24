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
    ListNode* partition(ListNode* head, int x) {
        ListNode* right = new ListNode(0);//dummy node
        ListNode* left = new ListNode(0);//dummy node

        ListNode * rightList = right; //right->(0|NULL),rightList->(0) in right
        ListNode * leftList = left; //left->(0|NULL),leftList->(0) in left

        while(head){
            if(head->val<x){
                leftList->next=head;
                leftList=leftList->next;

            }
            else{
                rightList->next=head;
                rightList=rightList->next;

            }
            head=head->next;
        }
        //connecting both
        leftList->next=right->next;
        rightList->next=nullptr;
        return left->next;

    }
};