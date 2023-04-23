### 基本思想：
- 堆排序过程如下：
  1. 用数列构建出一个大顶堆(size = n)，取出堆顶的数字；
  2. 调整剩余的数字，构建出新的大顶堆 (size = n - i， 其中i为已经sorted的数字)，再次取出堆顶的数字；
  3. 循环往复，完成整个排序。
- 我们先要了解完全二叉树的几个性质。将根节点的下标视为 0，则完全二叉树有如下性质：
  1. 对于完全二叉树中的第 i 个数，它的左子节点下标：left = 2i + 1
  2. 对于完全二叉树中的第 i 个数，它的右子节点下标：right = left + 1
  3. 对于有 n 个元素的完全二叉树(n≥2)，它的最后一个非叶子结点的下标：n/2 - 1
- 复杂度：
  1. 根据数学运算可以推导出初始化建堆的时间复杂度为O(n)，重建堆的时间复杂度为O(nlogn)，所以堆排序总的时间复杂度为O(nlogn)。推导过程较为复杂，故不再给出证明过程。
  2. 堆排序的空间复杂度为O(1)，只需要常数级的临时变量。
  3. 堆排序是一个优秀的排序算法，但是在实际应用中，快速排序的性能一般会优于堆排序，

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/sort-algorithms/eu7ux3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
### 实现代码:
```
// i为当前子树的根节点的序号，而heapSize不仅是要调整的heap的size，也是当前当前子树的最后一个节点的序号。
void heapify(vector<int> &nums, int i, int heapSize){
        int l = 2 * i + 1;//找到当前根节点的左子节点序号
        int r = l + 1;//找到当前根节点的右子节点序号
        int largest = i;//假设当前根节点为largest

        //如果左子节点比根节点大，那么largest就是左子节点
        if(l < heapSize && nums[l] > nums[largest])
            largest = l;
        //如果右子节点比根节点大，那么largest就是右子节点
        if(r < heapSize && nums[r] > nums[largest])
            largest = r;
        /*如果largest节点（假设叫他节点X）不是根节点，说明数需要有变化，那么首先把largest节点（X）变成根节点，然后旧的根结点的序号就变成了X节点的原序号largest。
        为了判断旧的根节点是否还需要继续下移，我们以旧根节点序号开始递归，如果他的子树中还有比他大的数字，则它还需要继续下移。*/
        //如果largest节点是根节点，那么不需要做什么
        if(largest != i){
            swap(nums[i], nums[largest]);
            heapify(nums, largest, heapSize);
        }
    }

    /*构建第一个大顶堆的方式是从第一个非叶子节点开始，调整当前节点为根节点的子树成大顶堆；调整完之后forloop下一层开始遍历到当前节点的左邻兄弟节点，
    并调整以它为根节点的子树成大顶堆，如此不断遍历，当层完后往上一层，直到回到根节点再调整最后一次（所以i >= 0而不是i > 0）。*/
    void buildMaxHeap(vector<int> &nums){
        for(int i = nums.size()/2-1; i >= 0; i--)
            heapify(nums, i, nums.size());
    }

    void heapSort(vector<int> &nums){
        buildMaxHeap(nums); //首先构建出第一个大顶堆
        for(int i = nums.size()-1; i > 0; i--){
            swap(nums[i],nums[0]);  //把堆顶的数字放入最后一位，不再参与排序。
            heapify(nums, 0, i);    //调整剩余的数字，构建出新的大顶堆，再次取出堆顶的数字
        }
    }
```