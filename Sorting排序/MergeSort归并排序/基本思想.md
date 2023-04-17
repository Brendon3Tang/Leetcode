### 参考文献
[CSDN： 十大经典排序算法-归并排序算法详解](https://blog.csdn.net/qq_35344198/article/details/106857042)

### 例题
[148. 排序链表](https://leetcode.cn/problems/sort-list/)
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

示例 1：
```
输入：head = [4,2,1,3]
输出：[1,2,3,4]
```
示例 2：
```
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
```
示例 3：
```
输入：head = []
输出：[]
```

提示：
```
链表中节点的数目在范围 [0, 5 * 104] 内
-10^5 <= Node.val <= 10^5
```
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 代码
```
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
    ListNode* findMid(ListNode* head){
        if(head == nullptr) return head;
        ListNode* fast = head->next, *slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* node1, ListNode* node2){
        ListNode* dummyHead = new ListNode(-1);
        ListNode* cur = dummyHead;
        while(node1 && node2){
            if(node1->val < node2->val){
                cur->next = node1;
                node1 = node1->next;
            }
            else{
                cur->next = node2;
                node2 = node2->next;
            }
            cur = cur->next;
        }

        if(node1){
            cur->next = node1;
        }
        if(node2){
            cur->next = node2;
        }
        return dummyHead->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;//如果不判断head->next，那么会进入死循环。因为会一直不断的跑left = sortList(head)，无法退出
        
        ListNode* mid = findMid(head);
        ListNode* next = mid->next;
        mid->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(next);
        return merge(left, right);
    }
};
```