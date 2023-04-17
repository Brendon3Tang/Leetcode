## 原理：
- 希尔排序本质上是对插入排序的一种优化，它利用了插入排序的简单，又克服了插入排序每次只交换相邻两个元素的缺点。它的基本思想是：

  - 将待排序数组按照一定的间隔分为多个子数组，每组分别进行插入排序。这里按照间隔分组指的不是取连续的一段数组，而是每跳跃一定间隔取一个值组成一组
  - 逐渐缩小间隔进行下一轮排序
  - 最后一轮时，取间隔为1，也就相当于直接使用插入排序。但这时经过前面的「宏观调控」，数组已经基本有序了，所以此时的插入排序只需进行少量交换便可完成




## 代码：
```
class Solution {
public:
    //插入排序的移动法
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
    //希尔排序：与插入排序的移动法一模一样，除了间隔是gap而不是1
    void shellSort(vector<int> &nums) {
        for(int gap = nums.size()/2; gap > 0; gap /= 2){
            //类似插入排序
            for(int i = gap; i < nums.size(); i++){
                int currNum = nums[i];
                int preIndex = i - gap; //该组中上一个数字的index
                while(preIndex >= 0 && nums[preIndex] > currNum){
                    nums[gap + preIndex] = nums[preIndex];
                    preIndex -= gap;
                }
                nums[preIndex+gap] = currNum;
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        shellSort(nums);
        return nums;
    }
};
```