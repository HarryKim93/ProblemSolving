// https://leetcode.com/problems/can-make-palindrome-from-substring/
// O(N)

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<int> cache(1);
        vector<bool> ans;
        
        int sLen = s.length();
        int mask = 0;
        for (auto ch : s) 
            cache.emplace_back(mask ^= 1 << (ch - 'a'));
        
        for (auto &query : queries) 
            ans.emplace_back(__builtin_popcount(cache[query[1] + 1]^cache[query[0]]) / 2 <= query[2]);
        
        return ans;
    }
};