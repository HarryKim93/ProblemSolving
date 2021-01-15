// O(N)
// https://leetcode.com/problems/combination-sum/solution/

class Solution {
public:
    void combinationSum(vector<int>& candidates, int target, vector<int>& container, int idx) {
        if (target == 0) {
            ans.push_back(container);
        } else {
            for (int i = idx; i < candidates.size(); i++) {
                if (target - candidates[i] >= 0){
                    container.push_back(candidates[i]);
                    combinationSum(candidates, target - candidates[i], container, i);
                    container.pop_back();
                } else {
                    break;
                }
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, tmp, 0);
        
        return ans;
    }
    
private:
    vector<vector<int>> ans;
};