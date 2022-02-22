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
 * 思路：用递归与count来track node，只有是奇数的node时才会swap。
 * 难点：c++的指针如何swap node
 */
class Solution {
public:
    int count = 0;
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
    
        count++;
        
        head->next = swapPairs(head->next);
       
        if((count % 2) != 0 && head->next != NULL)
        {
            //假设此时有linkedlist 1->2->4->3,且此时在node 1上。
            ListNode* tmp = head; //保存head,即保存1->2->4->3,此时的head/tmp = 1->2->4->3
            ListNode* tmpNext = head->next; //保存head->next，即保存2->4->3，即此时tmpNext/head->next = 2->4->3
            head->next = tmpNext->next; //先将swap前的head的next改成swap前的head->next的next。此时的head是1，即
                                        //此时的head/tmp从1->2->4->3变成1->4->3
            head = tmpNext; //更新head，即此时linkedlist从1->2->4->3变成了2->4->3
            head->next = tmp; //更新head->next,即此时linkedlist为2->1->4->3
        }
        count--;
        return head;   
    }
};