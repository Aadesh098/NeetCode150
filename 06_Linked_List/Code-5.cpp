// Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/description/

void helper1(Node* head){
        Node* temp = head ;
        while(temp){
            Node* nextNode = temp->next ;
            Node* copyNode = new Node(temp->val);
            temp->next = copyNode ;
            copyNode->next = nextNode ;
            temp = nextNode ;
        }
    }

    void helper2(Node* head){
        Node* temp = head ;
        while(temp){
            Node* copyNode = temp->next ;
            if(temp->random){
                copyNode->random = temp->random->next ;
            }else{
                copyNode->random = NULL ;
            }
            temp = temp->next->next ;
        }
    }

    Node* helper3(Node* head){
        Node* temp = head ;
        Node* dummy = new Node(-1);
        Node* res = dummy ;
        while(temp){
            res->next = temp->next ;
            res = res->next ;
            temp->next = temp->next->next;
            temp = temp->next ;
        }
        return dummy->next ;
    }
   
    Node* copyRandomList(Node* head) {
        helper1(head);
        helper2(head);
        return helper3(head);        
    }