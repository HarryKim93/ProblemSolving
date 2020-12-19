// https://leetcode.com/problems/high-five/submissions/
// O(N)

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, vector<int>> umap;
        vector<vector<int>> vec;
        
        auto retVector = [=](int id, vector<int>& vec) {
            int average = 0;
            for (int i = 0; i < 5; i++) average += vec[i];
            return vector<int>{id, average / 5};
        };
        
        for (auto item : items) umap[item[0]].push_back(item[1]);
        for (auto iter = umap.begin(); iter != umap.end(); iter++) {
            sort(iter->second.begin(), iter->second.end(), [=](const int& a, const int& b){return a > b;});
            vec.emplace_back(retVector(iter->first, iter->second));
        }
        
        sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        return vec;
    }
};