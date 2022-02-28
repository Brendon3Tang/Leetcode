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

/*
 * logic: 把序号为odd的节点与序号为even的节点分别存入两个stack中（存入之前要断开链表），然后重新构造链表。
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        stack<ListNode*> odd;
        stack<ListNode*> even;
        ListNode* tmp = head;
        ListNode* tmp2 = tmp;
        int count = 1;
        while (tmp != NULL)
        {
            tmp2 = tmp->next;
            tmp->next = NULL;

            if (count % 2 != 0)
                odd.push(tmp);
            else
                even.push(tmp);
            
            count ++;
            tmp = tmp2;
        }
        tmp = NULL;
        
        while(!even.empty())
        {
            even.top()->next = tmp;
            tmp = even.top();
            even.pop();
        }

        while(!odd.empty())
        {
            odd.top()->next = tmp;
            tmp = odd.top();
            odd.pop();
        }
        head = tmp;
        return head;
    }
};