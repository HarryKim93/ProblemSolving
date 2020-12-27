// https://leetcode.com/problems/regular-expression-matching/
// O(S * P)

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct hash_pair { 
        template <class T1, class T2> 
        size_t operator()(const pair<T1, T2>& p) const
        { 
            auto hash1 = hash<T1>{}(p.first); 
            auto hash2 = hash<T2>{}(p.second); 
            return hash1 ^ hash2; 
        } 
    }; 
  
    
    bool isMatch(string s, string p) {
        unordered_map<pair<int, int>, bool, hash_pair> cache;
        
        function<bool(int, int)> dp = [&](int i, int j) -> bool{
            bool ans = false;
            bool first_match = false;
            
            if (cache.find(make_pair(i, j)) == cache.end()) {
                if (j == p.length()) ans = (i == s.length());
                else {
                    first_match = i < s.length() && (p[j] == s[i] || p[j] == '.');
                    if (j + 1 < p.length() && p[j + 1] == '*') 
                        ans = dp(i, j + 2) || (first_match && dp(i + 1, j));
                    else
                        ans = first_match && dp(i + 1, j + 1);
                }
                    
                cache[make_pair(i, j)] = ans;
            }
            
            return cache[make_pair(i, j)];
        };
        
        return dp(0, 0);
    }

    bool isMatch2(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        
        bool dp[sLen + 1][pLen + 1];
        for (int i = 0; i <= sLen; i++) memset(dp[i], false, pLen + 1);
        
        dp[sLen][pLen] = true;
        for (int i = sLen; i >= 0; i--) {
            for (int j = pLen - 1; j >= 0; j--) {
                bool first_match = i < sLen && (p[j] == s[i] || p[j] == '.');
                
                if (j + 1 < pLen && p[j + 1] == '*') 
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                else 
                    dp[i][j] = first_match && dp[i + 1][j + 1];
            }
        }
        
        return dp[0][0];
    }
};