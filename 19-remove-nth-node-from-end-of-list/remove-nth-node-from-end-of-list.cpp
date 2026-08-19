class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;

        while (temp) {
            len++;
            temp = temp->next;
        }

        if (len == 1 && n == 1)
            return NULL;

        if (n == len)
            return head->next;

        temp = head;
        int d = len - n;

        for (int i = 1; i < d && temp; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};