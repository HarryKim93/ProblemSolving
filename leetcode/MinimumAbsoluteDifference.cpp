// https://leetcode.com/problems/minimum-absolute-difference/
// O(N)

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int retMin = INT_MAX;
        
        vector<vector<int> > ret;
        for (int i = 0; i < arr.size() - 1; i++) {
            retMin = min(retMin, arr[i + 1] - arr[i]);
        }
        
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] - arr[i] == retMin) ret.emplace_back(vector<int>({arr[i], arr[i + 1]}));
        }
        
        return ret;
    }
};