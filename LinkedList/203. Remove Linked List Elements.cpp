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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = head;
        ListNode* tmp = head;
        while(tmp != NULL)
        {
            if(tmp->val == val)
            {
                if(tmp == head)
                {
                    pre = head->next;
                    tmp = head->next;
                    head->next = NULL;
                    delete head;
                    head = tmp;
                }
                else if(tmp->next == NULL)
                {
                    delete tmp;
                    pre->next = NULL;
                    tmp = NULL;
                }
                else
                {
                    pre->next = tmp->next;
                    tmp->next = NULL;
                    delete tmp;
                    tmp = pre->next;
                }
            }
            else
            {
                pre = tmp;
                tmp = tmp->next;
            }
        }
        return head;
    }
};