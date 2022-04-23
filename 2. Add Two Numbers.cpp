/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int size1 = 1;
        int size2 = 1;
        ListNode* temp = l1;
        while(temp != NULL)
        {
            size1++;
            temp = temp->next;
        }
        temp = l2;
        while(temp != NULL)
        {
            size2++;
            temp = temp->next;
        }
        
        if(size1 >= size2)
        {
            l1 = addHelper(l1, l2, 0);
            return l1;
        }
        else
        {
            l2 = addHelper(l2, l1, 0);
            return l2;
        }
        
        return l1;
    }
    
    ListNode* addHelper(ListNode* l1, ListNode* l2, int flag)
    {
        if(l1 == NULL && flag == 0)
            return l1;
        if(l1 == NULL && flag == 1)
        {
            ListNode* newNode = new ListNode(flag, NULL);
            return newNode;
        }
        
        if(l2 == NULL)
        {
            l1->val += flag;
            flag = 0;
            
            if(l1->val > 9)
            {
                l1->val = l1->val % 10;
                flag = 1;
            }
            
            l1->next = addHelper(l1->next, l2, flag);
            return l1;
        }
        
        l1->val = l1->val + l2->val;
        
        if(flag == 1)
        {
            l1->val += flag;
            flag = 0;
        }
        
        if(l1->val > 9)
        {
            l1->val = l1->val % 10;
            flag = 1;
        }
        
        l1->next = addHelper(l1->next, l2->next, flag);
        
        return l1;
    }
};