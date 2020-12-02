class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        else {
            queue<char> q;
            unordered_map<char, bool> umap;
            int sLen = s.length();
            
            q.push(s[0]);
            umap[s[0]] = true;
            int sum = 1;
            int ans = 1;
            
            for (int i = 1; i < sLen; i++) {
                if (umap.find(s[i]) != umap.end() && umap[s[i]] == true) {
                    while (q.front() != s[i]) {
                        umap[q.front()] = false;
                        q.pop();
                        sum--;
                    }
                    
                    q.pop();
                    sum--;
                }
                
                q.push(s[i]);
                umap[s[i]] = true;
                sum++;
                ans = max(ans, sum);
            }
            
            return ans;
        }
    }
};