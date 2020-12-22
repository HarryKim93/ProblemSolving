// O(N)
// https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_map<char, bool> umap;
        
        for (auto ch : J) 
            umap[ch] = true;
        
        for (auto ch : S)
            if (umap.find(ch) != umap.end()) res++;
        
        return res;
    }
};