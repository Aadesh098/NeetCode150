// Reverse Linked List 
// https://leetcode.com/problems/reverse-linked-list/description/

// Algorithm 
// 1. If list is empty or has a single node -> return head
// 2. Create 2 variables prev=NULL , curr=head to help with reversal
// 3. Initiate a loop till (curr)
// 4. Create a variable temp to store curr->next 
// 5. Reverse the node 

// 6. Return prev

ListNode *reverseList(ListNode *head){
        if (head == NULL || head->next == NULL){
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }