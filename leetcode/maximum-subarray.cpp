// https://leetcode.com/problems/maximum-subarray/submissions/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int tmp = nums[0] > 0 ? nums[0] : 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (ans < 0) {
                ans = max(ans, nums[i]);
                tmp = ans > 0 ? ans : 0;
            } else {
                if ((nums[i] + tmp) > 0) {
                    tmp += nums[i];
                    ans = max(ans, tmp);    
                } else {
                    tmp = 0;
                }
            }
        }
        
        return ans;
    }
};