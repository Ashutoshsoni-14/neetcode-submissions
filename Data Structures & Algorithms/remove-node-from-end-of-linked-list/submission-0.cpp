class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Two pointer approach 
        ListNode * slow = head;
        ListNode * fast = head;
        for(int i = 1 ;i<=n;i++){
            fast = fast->next;
        }
        if(fast == NULL) return head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
