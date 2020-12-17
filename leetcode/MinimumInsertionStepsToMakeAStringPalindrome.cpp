// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// O(N) ?

class Solution {
public:
    int minInsertions(string s) {
        if (s.length() == 1) return 0;
        else {    
            string s2 = s;
            reverse(s2.begin(), s2.end());
            
            int len = s.length() / 2 + 1, len2 = s2.length() / 2 + 1;
            vector<vector<int>> table(len + 1, vector<int>(len2 + 1, 0));
            
            int ans = 0;
            int ret = 0;
            
            for (int i = 1; i <= len; i++) {
                for (int j = 1; j <= len2; j++) {
                    if (s[i - 1] == s2[j - 1]) 
                        table[i][j] = table[i - 1][j - 1] + 1;
                    else 
                        table[i][j] = max(table[i - 1][j], table[i][j - 1]); 
                    
                    ret = table[i][j] * 2;
                    if (j == len2) ret--;
                    ans = max(ans, ret);
                }
                len2--;
            }

            return len - ans;
        }
    }
};