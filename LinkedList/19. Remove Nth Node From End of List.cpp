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
 * 用count trace n, 用recursion，每次返回到上一层之前就使count++（etc.返回到倒数第1层时count = 1,返回到倒数第二层时count = 2）。
 * 用recursion的逻辑：到NULL结点时返回NULL，其余节点返回head,每一层使当前head->next = 下一层的head。
 * 如果n是1，则当当前head是倒数第一个，则直接返回NULL（相当于删除了该node）。否则当n！=1时，trace到倒数第n个node时，
 * 使当前head=当前head->next,然后返回当前head。
 */
class Solution {
public:
    int count = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
        {
            count++;
            return NULL;
        }
        
        head->next = removeNthFromEnd(head->next, n);
        
        if(count == n)
        {
            if(head->next == NULL)
            {
                count++;
                return NULL;
            }
            else
            {
                ListNode* tmp = head->next;
                head->next = NULL;
                delete head;
                head = tmp;
            }
        }
        count++;
        return head;
    }
};