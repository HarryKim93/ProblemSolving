// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// O(N) ?

class Solution {
public:
    int minInsertions(string s) {
        if (s.length() == 1) return 0;
        else {
            int searchLen = s.length() - 1;
            string strL = s; 
            string strR = s;
            
            int num = s.length() / 2;
            
            for (int i = 0; i < num; i++) {
                swap(strR[i], strR[searchLen - i]);    
            }
            
            int beforeMap[26];
            int afterMapR[26];
            int afterMapL[26];
            
            memset(beforeMap, 0, 26);
            memset(afterMapR, 0, 26);
            memset(afterMapL, 0, 26);
            
            beforeMap[s[searchLen] - 'a'] = 1;
            beforeMap[s[0] - 'a'] = 1;
            afterMapR[s[0] - 'a'] = 1;
            afterMapL[s[searchLen] - 'a'] = 1;
            
            for (int i = 1; i < searchLen; i++) {
                beforeMap[s[i] - 'a']++;
                afterMapR[s[i] - 'a'] += 2;
                afterMapL[s[i] - 'a'] += 2;
                
                strR.push_back(s[i]);
                strL.push_back(s[searchLen - i]);
            }
            
            afterMapR[s[searchLen] - 'a']++;
            strR.push_back(s[searchLen]);
            afterMapL[s[0] - 'a']++;
            strL.push_back(s[0]);
            
            int left = searchLen - 1, right = searchLen;
            while (afterMapL[strL[left] - 'a'] - 1 >= beforeMap[strL[left] - 'a'] && afterMapL[strL[right] - 'a'] - 1 >= beforeMap[strL[right] - 'a']) {
                afterMapL[strL[left] - 'a']--;
                afterMapL[strL[right] - 'a']--;
                left--;
                right++;
            }
            
            int L = (strL.length() - (right - left - 1)) - s.length();
            
            left = searchLen - 1, right = searchLen;
            while (afterMapR[strR[left] - 'a'] - 1 >= beforeMap[strR[left] - 'a'] && afterMapR[strR[right] - 'a'] - 1 >= beforeMap[strR[right] - 'a']) {
                afterMapR[strR[left] - 'a']--;
                afterMapR[strR[right] - 'a']--;
                left--;
                right++;
            }
            
            int R = (strR.length() - (right - left - 1)) - s.length();
            
            return min(L, R);
        }
    }
};