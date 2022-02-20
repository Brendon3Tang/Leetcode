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
        ListNode* temp1, *temp2;
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
        return head;
    }
};