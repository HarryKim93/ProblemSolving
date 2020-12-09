// https://leetcode.com/problems/longest-string-chain/
// O(N^2 * word)

class Solution {
public:    
    int longestStrChain(vector<string>& words) {
        int ans = 0;
        int wordsLen = words.size();
        
        bool cache[wordsLen];
        memset(cache, 0, wordsLen);
        
        function<bool(string&, string&)> checkChain = [](const string& a, const string &b) {
            int lenA = a.length(), lenB = b.length();

            int i = 0;
            for (auto ch : a)
                for (; i < lenB; i++)
                    if (ch == b[i]) {
                        lenA--;
                        break;
                    }   

            return lenA == 0;
        };

        function<void(int, int)> cal = [&](int idx, int step) {
            if (idx != -1) {
                ans = max(ans, step);
                cache[idx] = true;
            }
            
            for (int i = idx + 1; i < wordsLen; i++) {
                if (cache[i]) continue;
                else if (idx == -1) cal(i, step + 1);
                else if (words[idx].length() == words[i].length()) continue;
                else if (words[idx].length() + 1 < words[i].length()) break;
                else if (checkChain(words[idx], words[i])) cal(i, step + 1);
            }
        };
        
        sort(words.begin(), words.end(), [](const string& a, const string& b){return a.length() < b.length();});
        cal(-1, 0);
        
        return ans;
    }
};