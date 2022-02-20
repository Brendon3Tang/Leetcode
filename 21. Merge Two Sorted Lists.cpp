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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*ListNode* temp1, *temp2;
        temp1 = list1;
        temp2 = list2;
        
        //用multiset把list1与list2全部存入并且排序
        multiset<int> mySet;
        while(temp1 != NULL)
        {
            mySet.insert(temp1->val);
            temp1 = temp1->next;
        }
        
        while(temp2 != NULL)
        {
            mySet.insert(temp2->val);
            temp2 = temp2->next;
        }
        
        //multi Set的已经从小到大进行排序。从set的末尾开始，创建一个node并存入最大Value并保存当前node到tmp, 由于此时没有nextNode，因此直接进入set的前一个val，并且再创建一个node，
        //由于此时有nextNode（即之前保存的tmp Node),因此使current newNode->next = tmp。然后保存当前node到tmp以备下次使用。当到达set的开头时（Rend的前一位），保存当前node为head node，并
        //最终返回head node
        ListNode* tmp = NULL;
        ListNode* head = NULL;
        for(multiset<int>::reverse_iterator rit=mySet.rbegin(); rit!=mySet.rend(); ++rit)
        {
            ListNode *newNode = new ListNode();
            newNode->val = *rit;
            if(tmp != NULL)
            { 
                newNode->next = tmp;
            }
            if(rit == --mySet.rend())
            {
                head = newNode;
            }
            tmp = newNode;
        }
        return head;*/

        /*
        * 使用递归：由于新的linked list是从小到大排列，因此小的node肯定在前方。比较两个node，较小的那个node在靠前位置，因此我们使用较小node->next
        * 最好带入例子进行理解 如list1 [1], list2 [2]/ list1 [1,2,3], list2 [4,5,6]
        */
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        if(list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};