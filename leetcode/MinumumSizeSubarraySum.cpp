// https://leetcode.com/problems/minimum-size-subarray-sum/submissions/
// O(n)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int left = 0, right = 0, ans = INT_MAX;
        
        int sum = 0;
        while (right < nums.size()) {
            sum += nums[right++];
            
            while (sum >= s) {
                ans = min(ans, right - left);
                sum -= nums[left++];
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};