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
    ListNode* reverseList(ListNode* curHead) {
        if(curHead == NULL || curHead->next == NULL)
            return curHead;//链表为空时或者达到末尾node时，return当前的curHead
        
        ListNode *newNext = curHead->next;//得到curHead的next
        ListNode *newHead = reverseList(newNext);//传入next node开始递归，当到达末尾node时，return到倒数第二层递归的node（此时curHead为链表的倒第二个node），并得到newHead
        newNext->next = curHead;//newNext始终指向curHead的next Node,因此可以开始建立翻转链表
        curHead->next = NULL;//将旧链表的箭头全部消除
        return newHead;//递归的每层都要返回newHead
    }
};