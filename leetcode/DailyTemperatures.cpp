// O(N)
// https://leetcode.com/problems/daily-temperatures/solution/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> stk;
        stk.push(make_pair(T[0], 0));
        
        vector<int> ans(T.size());
        
        for (int i = 1; i < T.size(); i++) {
            while (!stk.empty() && stk.top().first < T[i]) {
                auto item = stk.top();
                stk.pop();
                
                ans[item.second] = i - item.second;
            }
            
            stk.push(make_pair(T[i], i));
        }
        
        ans[T.size() - 1] = 0;
        
        return ans;
    }
};