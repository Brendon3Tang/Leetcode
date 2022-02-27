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
 * logic: 贪心算法，递归。
 * 1.当k>=nodeNum时，每个linkedlist的part固定只需要1个node（size固定为1）。
 * 2.当k<nodeNum时，根据当前的nodeNum,k决定每个part的size,将当前能容纳的最大的size放入当前的linkedList的part。新size = ceil[(nodeNum-size)/(k-1)]。然后从用递归在剩余的node中寻找
 * 下一个part的最大size： recursionFunction(vector, curHead, k-1, nodeNum-size, size = ceil(nodeNum/k))
 *      a.k-1是因为在进行完一次分配后，需要的part k就减1。
 *      b.nodeNum-size是因为每分配一part后，剩余的nodeNum就会减去该part的size
 *      c.新size为需要用新的k与nodeNum更新后的size。
 *      d.注意用ceil得保证至少一个data type是double,否则在用ceil之前compiler就会把新的int的小数删除
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        double nodeNum = 0;
        int size = 0;
        ListNode *tmp = head;
        vector<ListNode*> v;
        while(tmp != NULL)
        {
            nodeNum++;
            tmp = tmp->next;
        }
        
        if(nodeNum <= k)
        {
            for(int i = 0; i < k; i++)
            {
                if(head == NULL)
                    v.push_back(NULL);
                else
                {
                    ListNode* tmp = head->next;  
                    head->next = NULL;
                    v.push_back(head);
                    head = tmp;
                }
            }
        }
        else
        {
            size = ceil(nodeNum / k);
            splitHelper(v,head,k,nodeNum,size);
        }
        return v;
    }
    

    void splitHelper(vector<ListNode*> &v, ListNode* &curHead, int k, double nodeNum, int size)
    {
        if(curHead == NULL)
            return;
        
        ListNode* tmp;
        ListNode* tmpHead = curHead;
        for(int track = 1; track < size; track++)
            curHead = curHead->next;
        
        tmp = curHead->next;
        curHead->next = NULL;
        
        v.push_back(tmpHead);
        
        if(tmp == NULL)
            return;
        int newSize = ceil((nodeNum-size)/(k-1));
        splitHelper(v, tmp, k-1, nodeNum - size, newSize);
        return;
    }
};