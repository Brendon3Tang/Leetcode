/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> mySet;
        
        ListNode* tmp = head;
        while(tmp != NULL)
        {
            if(mySet.find(tmp) != mySet.end())
                return true;
            else
                mySet.insert(tmp);
            tmp = tmp->next;
        }
        return false;
    }
};