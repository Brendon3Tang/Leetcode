## 插入排序
- 插入排序的思想非常简单，生活中有一个很常见的场景：在打扑克牌时，**我们一边抓牌一边给扑克牌排序**，每次摸一张牌，就将它插入手上已有的牌中合适的位置，逐渐完成整个排序。
- 排序基本有序时，或者待排序的记录较少时，效率较高

- **插入排序的交换法**：在新数字插入过程中，不断与前面的数字交换，直到找到自己合适的位置。
- **插入排序的移动法：**：在新数字插入过程中，先把新数字保存为curNum，使j = i - 1（cur的左一位），然后不断比较curNum与nums[ j ]：
  - 用whileloop，如果比 nums[ j ]小，那么就把左边的值右移，nums[j + 1] = nums[ j ]。
  - 如果一直遍历到开头时，curNum仍然比nums[ j ]小，说明curNum是最小的值，跳出循环，此时j = -1。
  - 如果比左边的值大，则说明找到了curNum的位置，j--后跳出循环，此时我们知道这个位置是j + 1。
  - 跳出while循环后 nums[j + 1] = curNum。
- 移动法相对于交换法的优化之处：交换法每次交换都需要进行三次赋值操作（把a给temp，把b给a，再把temp给b），而移动法之需要一次赋值操作。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/sort-algorithms/ev4tee/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

## 代码(交换法)：
```
class Solution {
public:
    void insertSort(vector<int> &nums){
        if(nums.size() <= 1)    return;
        for(int i = 1; i < nums.size(); i++){   //从第二个数字开始排序
            int j = i;
            while(j >= 1){
                if(nums[j] < nums[j-1])
                    swap(nums[j], nums[j-1]);
                j--;
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        insertSort(nums);
        return nums;
    }
};
```

## 代码（移动法）：
```
class Solution {
public:
    //移动法
    void insertSort(vector<int> &nums){
        if(nums.size() <= 1)    return;
        for(int i = 1; i < nums.size(); i++){
            int currNum = nums[i];
            int j = i - 1;
            while(j >= 0 && currNum < nums[j]){
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = currNum;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        insertSort(nums);
        return nums;
    }
};
```

# [147. 对链表进行插入排序](https://leetcode.cn/problems/insertion-sort-list/)
## 题目：
给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。

插入排序 算法的步骤:

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素。每次迭代时，从输入数据中删除一个元素(红色)，并就地插入已排序的列表中。

对链表进行插入排序。

示例 1：
```
输入: head = [4,2,1,3]
输出: [1,2,3,4]
```
示例 2：
```
输入: head = [-1,5,3,4,0]
输出: [-1,0,3,4,5]
```

提示：
```
列表中的节点数在 [1, 5000]范围内
-5000 <= Node.val <= 5000
```
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/insertion-sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## 代码
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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = head->next;
        ListNode* lastSorted = head;
        while(cur != nullptr){
            if(cur->val > lastSorted->val)  //只要cur的值大于sorted部分最后一个节点的值，说明cur不需要被排序
                lastSorted = cur;
            else{
                ListNode* prev = dummyHead;
                while(prev->next && prev->next->val < cur->val)
                    prev = prev->next;  //如果prev->next小于cur，右移prev。当prev->next >= cur时，不移动，此时prev仍然小于cur，而prev->next可以指向cur了。
                lastSorted->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            }
            cur = lastSorted->next;
        }
        return dummyHead->next;
    }
};
```