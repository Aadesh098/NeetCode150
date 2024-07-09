// Reorder List
// https://leetcode.com/problems/reorder-list/

ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    void merge(ListNode* l1, ListNode* l2) {
        while (l1) {
            ListNode* p1 = l1->next;
            ListNode* p2 = l2->next;
            l1->next = l2;
            if (p1 == NULL) {
                break;
            }
            l2->next = p1;
            l1 = p1;
            l2 = p2;
        }
    }

    void reorderList(ListNode* head) {
        if (head->next == NULL) {
            return;
        }
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* l1 = head;
        ListNode* l2 = reverse(slow);
        merge(l1, l2);
    }