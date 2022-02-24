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
* 逻辑： 遍历一遍链表，得到节点总数n。然后遍历n/2个节点并用stack储存前n/2个节点。然后在从第n/2个节点的下一个节点(（n/2）+1)继续遍历到链表末尾，如果任何一个cur Node != stack.top()，则return false。
* 每检查完一个curNode都需要pop一个stack中的值。另外，如果节点总数n为奇数时，在储存完前n/2个节点后，需要(（n/2）+2)个节点开始检查，因为第(（n/2）+1)个节点是中间点，如[1,0,1]中的0
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *tmp = head;
        stack<int> s1;
        int count = 0;
        while(tmp != NULL)
        {
            count++;
            tmp = tmp->next;
        }
        
        tmp = head;
        for(int i = 0; i < count/2; i++)
        {
            s1.push(tmp->val);
            tmp = tmp->next;
        }
        
        if(count%2 != 0)
        {
            tmp = tmp->next;
        }
        
        for(int j = 0; j < count/2; j++)
        {
            if(tmp->val != s1.top())
                return false;
            
            s1.pop();
            tmp = tmp->next;
        }
        return true;
        
    }
};