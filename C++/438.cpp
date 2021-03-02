class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        unordered_set<char> uset;
        unordered_map<char, int> umap;
        queue<char> q;
        
        for (const auto& ch : p) {
            uset.insert(ch);
            umap[ch]++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            q.push(s[i]);
            if (q.size() > p.size()) {
                char ch = q.front();
                q.pop();
                if (uset.count(ch)) {
                    umap[ch]++;
                    if (umap[ch] == 0) umap.erase(ch);
                }
            }
            
            if (uset.count(s[i])) {
                umap[s[i]]--;
                if (umap[s[i]] == 0) umap.erase(s[i]);
                if (umap.size() == 0) ret.push_back(i - (p.length() - 1));
            }
            
            // cout << i << "\n";
            // cout << umap[p[0]] << " " << umap[p[1]] << " " << umap[p[2]] << "\n";
        }
        
        return ret;
    }
};