class Solution {
public:
    int countSubstrings(string s) {
        int oleft = 0, oright = 0, eleft = 0, eright = 0;
        int ans = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length()) {
                oleft = i;
                oright = i + 1;
                while (s[oleft] == s[oright]) {
                    ans++;
                    oleft--;
                    oright++;
                    if (oleft < 0 || oright >= s.length()) break;
                }
            }
            if (i < s.length()) {
                eleft = eright = i;
                while (s[eleft] == s[eright]) {
                    ans++;
                    eleft--;
                    eright++;
                    if (eleft < 0 || eright >= s.length()) break;
                }
            }
        }
        
        return ans;
    }
};