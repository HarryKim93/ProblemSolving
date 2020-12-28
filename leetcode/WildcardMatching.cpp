// https://leetcode.com/problems/wildcard-matching/submissions/
// O(S * P)

class Solution {
public:
    struct hash_pair {
        template<class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            hash<T1> hash1;
            hash<T2> hash2;
            return hash1(p.first) ^ hash2(p.second);
        }
    };
    
    bool isMatch(string s, string p) {
//         if (s.empty()) {
//             if (p.empty()) return true;
//             return p[0] == '*' && isMatch(s, p.substr(1));
//         } 
        
//         if (p[0] == '*') {
//             return isMatch(s, p.substr(1)) || isMatch(s.substr(1), p);
//         } else {
//             bool first_match = (p[0] == s[0] || p[0] == '?');
//             return first_match && isMatch(s.substr(1), p.substr(1));
//         }
//         return isMatch(s.substr(1), p.substr(1));
        
        unordered_map<pair<int, int>, bool, hash_pair> dp;
        
        function<bool(int, int)> matching = [&](int i, int j) {
            if (dp.find(make_pair(i, j)) == dp.end()) {
                bool ans = false;
                
                if (i == s.length()) {
                    if (j == p.length()) return true;
                    return p[j] == '*' && matching(i, j + 1);
                }
                
                if (p[0] == '*') {
                    ans = matching(i, j + 1) || matching(i + 1, j);
                } else {
                    bool first_match = (p[j] == s[i]) || (p[j] == '?');
                    ans = first_match && matching(i + 1, j + 1);
                }
                
                dp[make_pair(i, j)] = ans;
                return ans;
            } else {
                return dp[make_pair(i, j)];
            }
        };
        
        return matching(0, 0);
    }
    

};