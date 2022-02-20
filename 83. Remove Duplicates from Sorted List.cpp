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
 * 使用递归：递归到最后一个node，然后返回前一个node，如果cur node的值与cur->next的值相等，则返回cur->next(删除cur),否则返回cur（同时返回了cur与cur->next这个sub linked list)。
 * 注意学习return的方法
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }
};