class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;

        vector<ListNode*> arr;

        ListNode* temp = head;

    
        while (temp) {
            arr.push_back(temp);
            temp = temp->next;
        }

        int l = 1;
        int r = arr.size() - 1;

        temp = head;

        while (l <= r) {

            temp->next = arr[r--];
            temp = temp->next;

  
            if (l <= r) {
                temp->next = arr[l++];
                temp = temp->next;
            }
        }

      
        temp->next = nullptr;
    }
};