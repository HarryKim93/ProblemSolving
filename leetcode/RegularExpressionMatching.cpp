class Solution {
public:
    void RefineString(string& target, string& source) {
        char repeatCh = '-';
        int pLen = source.length();
        for (int i = 0; i < pLen; i++) {
            if (source[i] == '*') {
                repeatCh = source[i - 1];
            } else {
                if (repeatCh == source[i]) continue;
                else {
                    repeatCh = '-';
                    target.push_back(source[i]);
                }
            }
        }
    }
    
    void RefineBack(string& target, string& source) {
        while (target.length() > 0 && source.length() > 0) {
            if (target.back() == source.back() || (target.back() == '.')) {
                target.pop_back();
                source.pop_back();
            } else {
                if (target.back() == '*') {
                    if (target[target.length() - 2] == '.') break;
                    if (target[target.length() - 2] == source.back()) { 
                        while (source.length() > 0 && target[target.length() - 2] == source.back()) source.pop_back();
                    }
                    target.pop_back();
                    target.pop_back();
                } 
            }
        }
    }
    
    bool isMatch(string s, string p) {
        string newP;
        
        RefineString(newP, p);
        RefineBack(newP, s);
        
        // Edge Point
        if (s.length() == 0) {
            if (p.length() == 0) return true;
            else {
                int newPlen = newP.length();
                int k = 0;
                
                while (k < newPlen) {
                    if (k + 1 < newPlen && newP[k + 1] == '*') k += 2;
                    else break;
                }
                
                return k == newPlen;
            }
        } else {
            int sLen = s.length(), pLen = newP.length();
            int i = 0, j = 0;
            while (i < sLen && j < pLen) {
                if (s[i] == newP[j] || newP[j] == '.') {
                    if (j + 1 < pLen && newP[j + 1] == '*') {
                        if (newP[j] == '.') return true;
                        while (i < sLen && s[i] == newP[j]) i++;
                        j += 2;
                    } else {
                        i++;
                        j++;
                    }
                } else {
                    if (j + 1 < pLen && newP[j + 1] == '*') j += 2;
                    else return false;
                }
            }
            
            return i == sLen && j == pLen;
        }
    }
};