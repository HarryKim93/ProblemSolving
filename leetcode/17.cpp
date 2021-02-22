// time = O(k^4)
// space = O(k^4)

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<string>> umap;
        umap[2] = {"a", "b", "c"};
        umap[3] = {"d", "e", "f"};
        umap[4] = {"g", "h", "i"};
        umap[5] = {"j", "k", "l"};
        umap[6] = {"m", "n", "o"};
        umap[7] = {"p", "q", "r", "s"};
        umap[8] = {"t", "u", "v"};
        umap[9] = {"w", "x", "y", "z"};
        
        function<vector<string>(vector<string>&, vector<string>&)> cal = [&](vector<string>& a, vector<string>& b) -> vector<string> {
            vector<string> ret;
            for (auto str : a) {
                for (auto str2 : b) {
                    ret.push_back(str + str2);
                }
            }
            
            return ret;
        };
        
        vector<string> ret = digits.size() > 0 ? umap[digits[0] - '0'] : vector<string>(0);
        for (int i = 1; i < digits.size(); i++) {
            ret = cal(ret, umap[digits[i] - '0']);
        }
        
        return ret;
    }
};