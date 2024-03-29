## [快速排序基本思想](https://blog.csdn.net/qq_28584889/article/details/88136498)：
- 通过一趟排序将要排序的数据分割成独立的两部分，分割点左边都是比它小的数，右边都是比它大的数。然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
### 代码
```
//快速排序（从小到大）
void quickSort(int left, int right, vector<int>& arr)
{
	if(left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		/*
		三种情况：
		一、当i < j且找到了小于base的arr[j]和大于base的arr[i]时，我们会互换arr[i]与arr[j]

		二、当找到了小于base的arr[j]，但没找到大于base的arr[i]而因此得到i == j的情况时，此时arr[i] == arr[j]，
		即arr[i]是小于base的，因此在while外基准数归位的时候会互换base和arr[i]，所以比base小的数还是在base左边

		三、当没找到小于base的arr[j]，因此直接得到j == i的情况时，此时arr[j] == arr[i]，
		此时的arr[i]是经过之前的swap后的数，因此他一定比base小，应该位于base左边。
		因此在while循环外基准数归位的时候会与base互换，所以
		还是会在base左边
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if(i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//递归左边
	quickSort(i + 1, right, arr);//递归右边
}
```
### 代码
```
//快速排序（从大到小）
void quickSort(int left, int right, vector<int>& arr)
{
	if(left >= right) //递归边界条件
		return;
	if(left < 0 || right >= arr.size())
	{
		cout << "error args! array bound." << endl;
		return;
	}//非法输入判断,防止数组越界
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] <= base && i < j)
			j--;
		while (arr[i] >= base && i < j)
			i++;
		if(i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//递归左边
	quickSort(i + 1, right, arr);//递归右边
}
```

### 代码：
```
// random选取pivot优化后
void quickSort(vector<int> &nums, int left, int right){
    if(left >= right)   return; //如果左指针大于右指针，说明到了边界条件，返回

    //因为我们通常选取第一个数作为pivot，所以如果要随机选取一个数作为pivot，我们要把这个数放在第一个位置
    int randomIdx = left + rand() % (right - left + 1);
    swap(nums[randomIdx], nums[left]);

    int i = left;
    int j = right;
    int pivot = nums[left]; //pivot要是放在第一个位置的数，但这个数可以是任何数（即之前swap了也没关系）
    int temp = 0;
    while(i < j){ 
        while(nums[j] <= pivot && i < j)//从右边开始，找到第一个大于pivot的数
            j--;
        while(nums[i] >= pivot && i < j)//从左开始，找到第一个小与pivot的数
            i++;
        if(i < j)//找到两个数后，如果此时i仍然在j左边，我们交换这两个数
            swap(nums[i], nums[j]);
    } 
    //当while循环完毕时，除了nums[i]，我们所有比pivot大的数都在pivot左边，所以比pivot小的数都在pivot右边。由于我们先j后i的顺序（先右后左的顺序）开始遍历，我们可以保证当i == j时，nums[i/j]一定小于pivot，所以此时我们把pivot与nums[i]交换。就完成了以这一个pivot为轴的sorting
    swap(nums[left], nums[i]);
    quickSort(nums, left, i-1);//然后以i为中点，递归地遍历i的左边与i的右边
    quickSort(nums, i+1, right); 
}
```

# Leetcode例题：
# [215. 数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/?favorite=2cktkvj)
### 题目：
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

示例 1:
```
输入: [3,2,1,5,6,4], k = 2
输出: 5
```
示例 2:
```
输入: [3,2,3,1,2,4,5,5,6], k = 4
输出: 4
```

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

### 思路：
1. 快排

### 难点：
1. 要求时间复杂度为 O(n) 的算法：快速排序需要用优化的思路，否则会超时。

### 代码：  
```
class Solution {
public:
        void quickSort(vector<int> &nums, int left, int right){
        if(left >= right)   return; //如果左指针大于右指针，说明到了边界条件，返回

        //因为我们通常选取第一个数作为pivot，所以如果要随机选取一个数作为pivot，我们要把这个数放在第一个位置
        int randomIdx = left + rand() % (right - left + 1);
        swap(nums[randomIdx], nums[left]);

        int i = left;
        int j = right;
        int pivot = nums[left]; //pivot要是放在第一个位置的数，但这个数可以是任何数（即之前swap了也没关系）
        int temp = 0;
        while(i < j){ 
            while(nums[j] <= pivot && i < j)//从右边开始，找到第一个大于pivot的数
                j--;
            while(nums[i] >= pivot && i < j)//从左开始，找到第一个小与pivot的数
                i++;
            if(i < j)//找到两个数后，如果此时i仍然在j左边，我们交换这两个数
                swap(nums[i], nums[j]);
        } 
        //当while循环完毕时，除了nums[i]，我们所有比pivot大的数都在pivot左边，所以比pivot小的数都在pivot右边。由于我们先j后i的顺序（先右后左的顺序）开始遍历，我们可以保证当i == j时，nums[i/j]一定小于pivot，所以此时我们把pivot与nums[i]交换。就完成了以这一个pivot为轴的sorting
        swap(nums[left], nums[i]);
        quickSort(nums, left, i-1);//然后以i为中点，递归地遍历i的左边与i的右边
        quickSort(nums, i+1, right); 
    }

    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size()-1);
        return nums[k-1];
    }
};
```
