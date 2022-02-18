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

        /*ListNode * cur, *newNext, *prev;
        newNext = NULL;
        prev = NULL;
        cur = curHead;
        while(cur != NULL)
        {
            newNext = cur->next;  //保存cur的下一个节点
            cur->next = prev;//把cur的next指向prev,开始翻转链表
            prev = cur;//保存cur给prev,在下一次循环中使用
            cur = newNext;//把cur指向当前cur的下一个节点，进行下一个节点的翻转，当cur的下一个节点为NULL时，结束循环
        }
        return prev;//在最后一次循环中prev保存了cur进入到NULL之前的最后一个节点（旧链表的末尾节点），即新的head节点，return这个节点*/
    }
};