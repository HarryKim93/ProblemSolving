// O(N)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && nums[-nums[i] - 1] > 0) {
                nums[-nums[i] - 1] = -nums[-nums[i] - 1];
            } else if (nums[i] > 0 && nums[nums[i] - 1] > 0) {
                nums[nums[i] - 1] = -nums[nums[i] - 1];
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) ans.push_back(i + 1); 
        }
        
        return ans;
    }
};