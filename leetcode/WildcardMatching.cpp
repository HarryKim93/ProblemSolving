// https://leetcode.com/problems/wildcard-matching/submissions/
// O(2^(min(S, P / 2))) or O(S * P)

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
        unordered_map<pair<int, int>, bool, hash_pair> dp;
        
        function<bool(int, int)> matching = [&](int i, int j) {
            bool ans = false;
            bool first_match = false;
            
            if (dp.find(make_pair(i, j)) == dp.end()) {
                if (j == p.length()) ans = (i == s.length());
                else {
                    first_match = (p[j] == s[i]) || (p[j] == '?');
                    if (p[j] == '*') {
                        ans = matching(i, j + 1) || (i < s.length() && matching(i + 1, j));
                    } else {
                        ans = first_match && matching(i + 1, j + 1);
                    }
                }
                
                dp[make_pair(i, j)] = ans;
            } 
            
            return dp[make_pair(i, j)];
        };
        
        return matching(0, 0);
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        const int sLen = s.length();
        const int pLen = p.length();
        
        bool dp[sLen + 1][pLen + 1];
        for (int i = 0; i <= sLen; i++) memset(dp[i], false, pLen + 1);
        
        dp[sLen][pLen] = true;
        for (int i = sLen; i >= 0; i--) {
            for (int j = pLen - 1; j >= 0; j--) {
                bool first_match = i < sLen && (p[j] == s[i] || p[j] == '?');
                
                if (p[j] == '*') 
                    dp[i][j] = (i < sLen && dp[i + 1][j]) || dp[i][j + 1];
                else 
                    dp[i][j] = first_match && dp[i + 1][j + 1];   
                
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    void cleanUp(string& p) {
        string newStr = "";
        if (p.length() != 0) {
            char prev = p[0];
            newStr.push_back(prev);
            for (int i = 1; i < p.length(); i++) {
                if (p[i] == '*' && p[i] == prev) continue;
                else {
                    newStr.push_back(move(p[i]));
                    prev = p[i];
                }
            }
        }
        
        p = move(newStr);
    }
    
    bool isMatch(string s, string p) {
        cleanUp(p);
        
        char dp[s.length() + 1][p.length() + 1];
        for (int i = 0; i <= s.length(); i++) for (int j = 0; j <= p.length(); j++) dp[i][j] = -1;    
        
        function<bool(int, int)> matching = [&](int i, int j) {
            bool first_match = false;
            
            if (dp[i][j] == -1) {
                if (j == p.length()) return dp[i][j] = (i == s.length());
                else {
                    if (p[j] == '*') {
                        return dp[i][j] = (i < s.length() && matching(i + 1, j)) || matching(i, j + 1);
                    } else {
                        first_match = i < s.length() && (p[j] == s[i] || p[j] == '?');
                        return dp[i][j] = first_match && matching(i + 1, j + 1);
                    }
                }
            } 
            
            return dp[i][j];
        };
        
        return matching(0, 0);
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        short s_idx = 0, p_idx = 0;
        short star_idx = -1, s_tmp_idx = -1;
        short sLen = s.length(), pLen = p.length();
        
        while (s_idx < sLen) {
            if (p[p_idx] == s[s_idx] || p[p_idx] == '?') {
                s_idx++;
                p_idx++;
            } else if (p[p_idx] == '*') {
                s_tmp_idx = s_idx;
                star_idx = p_idx;
                p_idx++;
            } else if(star_idx == -1){
                return false;
            } else {
                s_idx = s_tmp_idx + 1;
                s_tmp_idx = s_idx;
                p_idx = star_idx + 1;
            }
        }
        
        for (auto ch : p.substr(p_idx))
            if (ch != '*') return false;
        return true;
    }
};