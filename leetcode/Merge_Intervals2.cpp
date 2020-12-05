// https://leetcode.com/problems/merge-intervals/
// O(N * log(N))

class Solution {
public:    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){ return a[0] < b[0]; });
        
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                if (intervals[i][1] > ans.back()[1]) ans.back()[1] = intervals[i][1];
            }
            else ans.push_back(intervals[i]);
        }

        return ans;
    }
};