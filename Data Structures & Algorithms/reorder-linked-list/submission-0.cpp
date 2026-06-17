class Solution {
public:
    void reorderList(ListNode* head) {
        if(head->next == NULL || head->next->next == NULL){
            return ;
        }
        //1. middle -
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //Now slow is pointing to the middlw node - 

        //2. separate list
        ListNode * second = slow->next;
        slow->next = NULL;

        //3. reverse the second list 
        ListNode * prev = NULL;
        // second is curr
        while(second){
            ListNode * nextptr = second->next;
            second->next = prev;
            prev = second;
            second = nextptr;
        }
        //4. Merge two list-
        ListNode * first = head;
        second = prev;
        while(second){
            ListNode * temp1 = first->next;
            ListNode * temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1 ;
            second = temp2;
        }
        return ;
    }
};
