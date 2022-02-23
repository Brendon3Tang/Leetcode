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
* 思路：把两个linkedlist的node分别存入两个stack中。然后从top开始相加，如果大于等于10则需要进一位。只要s1,s2其中一个stack不为空，或者两者均为空但是carry不为0，都需要新建一个node
* 分类讨论：
* 1.当两个stack均不为空时，如果s1+s2+flag > 9,那么newNode->val = (s1+s2+flag) % 10,同时flag/carry = 1;如果s1+s2+flag <= 9,那么newNode->val = (s1+s2+flag) ,同时flag/carry = 0
* 2.当s1等于0时，如果s1+flag > 9，那么newNode->val = (s1 + flag) % 10, 同时flag/carry = 1；如果s1+flag <= 9, 那么newNode->val = (s1+flag)，同时flag/carry = 0;
* 3.当s2等于0时，如果s2+flag > 9，那么newNode->val = (s2 + flag) % 10, 同时flag/carry = 1；如果s2+flag <= 9, 那么newNode->val = (s2+flag)，同时flag/carry = 0;
* 4.当两个stack均为空时，如果flag/carry = 0，则说明全部运算已完成；如果flag/carry ！= 0，则说明要新建一个newNode储存val 1.
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        int flag = 0;
        ListNode* tmp = NULL;

        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        while (!s1.empty() || !s2.empty() || flag != 0)
        {
            int count = 0;
            //情况1 当两个stack均不为空时
            if (!s1.empty() && s2.empty())
            {
                if (s1.top() + flag > 9)
                {
                    count = (s1.top() + flag) % 10;
                    flag = 1;
                }
                else
                {
                    count = s1.top() + flag;
                    flag = 0;
                }
                s1.pop();
            }
            //情况2 当s1等于0时
            else if (s1.empty() && !s2.empty())
            {
                if (s2.top() + flag > 9)
                {
                    count = (s2.top() + flag) % 10;
                    flag = 1;
                }
                else
                {
                    count = s2.top() + flag;
                    flag = 0;
                }
                s2.pop();
            }
            //情况3 当s2等于0时
            else if(!s1.empty() && !s2.empty())
            {
                if (s1.top() + s2.top() + flag > 9)
                {
                    count = (s1.top() + s2.top() + flag) % 10;
                    flag = 1;
                }
                else
                {
                    count = s1.top() + s2.top() + flag;
                    flag = 0;
                }
                s1.pop();
                s2.pop();
            }
            //情况4 当两个stack均为空时，如果flag/carry ！= 0
            else
            {
                count = flag;
                flag = 0;
            }

            //根据上述情况得到count, 然后新建node,并用tmp储存当前node，以便下次使用next连接
            if (!tmp)
            {
                ListNode* newNode = new ListNode(count, NULL);
                tmp = newNode;
            }
            else
            {
                ListNode* newNode = new ListNode(count, tmp);
                tmp = newNode;
            }     
        }
        return tmp;
    }
};