// https://leetcode.com/problems/merge-intervals/
// O(N * log(N))

class Solution {
public:    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //start, end Point
        vector<pair<int, int> > container;
        vector<vector<int>> ans;
        int start, end, i;
        
        for (auto item : intervals) {
            container.emplace_back(make_pair(item[0], item[1]));
            container.emplace_back(make_pair(item[1], -1));
        }
        
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) -> bool { 
            if (a.first == b.first) 
                return a.second > b.second;
            return a.first < b.first; 
        };
        sort(container.begin(), container.end(), cmp);
        
        i = 0;
        while (i < container.size()) {
            if (container[i].second >= 0) {
                start = container[i].first;
                end = container[i].second;
                i++;
            }
            
            while (end != container[i].first || container[i].second != -1) {
                if (container[i].second >= 0) 
                    end = max(end, container[i].second);
                i++;
            }
            i++;
            
            if (ans.size() > 0 && ans.back()[0] == start && ans.back()[1] == end) continue;
            ans.emplace_back(vector<int>{start, end});
        }

        return ans;
    }
};