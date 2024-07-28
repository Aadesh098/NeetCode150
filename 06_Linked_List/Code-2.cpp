// Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/description/

// Algorithm 
// 1. If both lists are null -> return null 
// 2. If any of the list is null -> return the other list
// 3. Create 2 variables dummy to store the start of the merged linked list & curr=head to traverse the list
// 4. Initiate loop till (list1 != NULL && list2 != NULL)

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        ListNode* dummy = new ListNode();
        ListNode *curr = dummy;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1 == NULL) {
            curr->next = list2;
        } else {
            curr->next = list1;
        }
        return dummy->next;
    }