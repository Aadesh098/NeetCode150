// Reverse Linked List 
// https://leetcode.com/problems/reverse-linked-list/description/

ListNode *reverseList(ListNode *head){
        if (head == NULL || head->next == NULL){
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }