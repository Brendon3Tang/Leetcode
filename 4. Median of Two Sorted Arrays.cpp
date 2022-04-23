/*class Solution {
public:
    void makeVec(vector<int> nums1, vector<int> nums2, vector<double>& result, int i, int j){
        if(i == nums1.size() && j == nums2.size())
            return;
        else if(i == nums1.size())
        {
            result.push_back(nums2[j]);
            j++;
        }
        else if(j == nums2.size())
        {
            result.push_back(nums1[i]);
            i++;
        }
        else
        {
            if(nums1[i] <= nums2[j])
            {
                result.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                result.push_back(nums2[j]);
                j++;
            }
        }
        makeVec(nums1,nums2,result,i,j);
    }
        
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> result;
        makeVec(nums1,nums2,result,0,0);
        int length = 0;
        length = result.size();
        if(length % 2 == 0)
            return (result[length/2 - 1] + result[length/2])/2;
        else
            return result[length/2];
    }
};*/


class Solution {
public:      
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        while(i < nums2.size())
        {
            nums1.push_back(nums2[i]);
            i++;
        }
        sort(nums1.begin(), nums1.end());
        
        int length = nums1.size();
        double result;
        
        if(length % 2 == 0)
            result = ((double)nums1[length/2 - 1] + (double)nums1[length/2]) / 2;
        else
            result = nums1[length/2];
        
        return result;
    }
};