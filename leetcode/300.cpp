class Solution {
public:
    vector<int> cache;
    
    int getLIS(int idx, int count, const vector<int>& nums) {
        if (idx != -1 && count <= cache[idx]) {
            return INT_MIN;
        } else {
            if (idx != -1) cache[idx] = count;

            int ret = count;
            for (int i = idx + 1; i < nums.size(); i++) {
                if (idx == -1) {
                    ret = max(ret, getLIS(i, count, nums));
                } else {
                    if (nums[idx] < nums[i]) {
                        ret = max(ret, getLIS(i, count + 1, nums));
                    }
                }
            }
            
            return ret;
        }
    }
    
    int lengthOfLIS(vector<int>& nums) {
        cache = vector<int>(nums.size(), -1);
        return getLIS(-1, 1, nums);    
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ret = 1;
        vector<int> cache(nums.size(), 1);
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    if (cache[j] < cache[i] + 1) {
                        cache[j] = cache[i] + 1;
                        ret = max<int>(ret, cache[j]);
                    }
                }
            }
        }
        
        return ret;
    }
};