/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        
        ListNode *tmpA, *tmpB;
       
        tmpA = headA;
        tmpB = headB;
        while(tmpA != tmpB)
        {
            tmpA = tmpA->next;
            tmpB = tmpB->next;
            
            if(tmpA == NULL && tmpB != NULL)
                tmpA = headB;
            if(tmpB == NULL && tmpA != NULL)
                tmpB = headA;
        }
        
        return tmpA;
    }
};