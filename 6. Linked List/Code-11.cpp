// Reverse Nodes in K-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/

 ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        int count = k;
        while (curr) {
            if (count > 1) {
                ListNode* temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
                count--;
            } else {
                prev =s curr;
                curr = curr->next;
                count = k;
                ListNode* end = curr;
                for (int i = 0; i < k; i++) {
                    if (end == NULL) {
                        return dummy->next;
                    }
                    end = end->next;
                }
            }
        }
        return dummy->next;
    }