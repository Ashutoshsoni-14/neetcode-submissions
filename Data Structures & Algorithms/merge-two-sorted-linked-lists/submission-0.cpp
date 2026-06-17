class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode * ptr = list1;
        if(list1->val > list2->val){
            ptr = list2;
            list2 = list2->next;
        }
        else{
            list1 = list1->next;
        }
        ListNode * list = ptr;
        while(list1 && list2){
            if(list1->val < list2->val){
                list->next = list1;
                list1 = list1->next;
            }
            else{
                list->next = list2;
                list2 = list2->next;
            }
            list = list->next;
        }
        if(!list1) list->next = list2;
        else list->next = list1;
        return ptr;
    }
};
