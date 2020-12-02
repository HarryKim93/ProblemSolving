// https://leetcode.com/problems/maximum-subarray/submissions/

// maxSubArray[i] =max(maxSubArray[i], (maxSubArray[i - 1] > 0 ? maxSubArray[i - 1] : 0) + nums[i])

class Solution {
public:
    int maxSubArray(vector<int>& nums, int left, int right) {
        if (left == right) 
            return nums[left];
        
        int mid = (left + right) / 2;
        int lsum = nums[mid];
        int rsum = nums[mid];

        if (nums[mid] > 0) {
            while (lsum + nums[--mid] > 0) 
                lsum = lsum + nums[mid];
            lsum -= nums[mid];
            while (rsum + nums[++mid] > 0)
                rsum = rsum + nums[mid]; 
            rsum -= nums[mid];
        }

        return max(max(maxSubArray(nums, left, mid), maxSubArray(nums, mid, right)), max(max(lsum, rsum), lsum + rsum - nums[mid]));
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size());
    }
};