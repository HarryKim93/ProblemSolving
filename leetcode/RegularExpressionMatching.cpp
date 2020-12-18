class Solution {
public:
    bool isMatch(string s, string p) {        
        int i = 0, j = 0;
        int sLen = s.length() - 1;
        int pLen = p.length() - 1;
        
        if (sLen > 0 && p.length() == 0) return false;
        
        while (sLen >= 0 && pLen >= 0 && s[sLen] == p[pLen]) {
            sLen--;
            pLen--;
        }
        
        sLen++;
        pLen++;
        
        
        cout << sLen << " " << pLen << "\n";
        
        auto isAlpha = [](char ch) {return 0 <= ch - 'a' && ch - 'a' < 26;};
        while (i < sLen && j < pLen) {
            if (j + 1 < pLen && p[j + 1] == '*') {
                j++;
                continue;
            } else {
                if (p[j] == '*') {
                    if (p[j - 1] == '.') {
                        if (j + 1 == pLen) return true;
                        else 
                            while (i < pLen && p[j + 1] == s[i]) i++;
                    }
                    else {
                        while (i < pLen && p[j - 1] == s[i]) i++;
                    }
                    j++;
                }
                else if (p[j] == '.') {
                    j++;
                    i++;
                }
                else {
                    if (s[i] == p[j]) i++;
                    j++;
                }
            }
        }
        
        cout << i << " " << j << "\n";
        return i == sLen && j == pLen;
    }
};