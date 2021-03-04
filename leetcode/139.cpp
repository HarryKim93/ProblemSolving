// time : O(N^3)
// space : O(N^2)

class Solution {
public:
    unordered_set<string> uset;
    vector<vector<int>> vec;
    
    bool wordBreak(const string& str, int stIdx, int edIdx) {
        if (vec[stIdx][edIdx] != -1) return vec[stIdx][edIdx];
        else if (uset.count(str.substr(stIdx, edIdx - stIdx))) return vec[stIdx][edIdx] = true;
        else {
            bool ret = false;
            for (int i = stIdx + 1; i < edIdx; i++) {
                ret = wordBreak(str, stIdx, i) && wordBreak(str, i, edIdx);
                if (ret) {
                    ret = true;
                    break;
                }
            }
            
            return vec[stIdx][edIdx] = ret;
        }
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for (const auto& word : wordDict) uset.insert(word);
        vec = vector<vector<int>>(s.length() + 1, vector<int>(s.length() + 1, -1));
        
        return wordBreak(s, 0, s.length());
    }
};

// time : O(N^3)
// space : O(N)

class Solution {
public:
    struct Node {
        string str;
        int endIdx;
        Node(string _str, int _endIdx) : str(_str), endIdx(_endIdx) {}
    };
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        vector<bool> visited(s.length(), false);
        
        queue<Node> q;
        for (int i = 1; i <= s.length(); i++) {
            string temp = s.substr(0, i);
            if (uset.count(temp)) {
                q.push(Node(temp, i));
            }
        }
        
        while (!q.empty()) {
            Node temp = q.front();
            q.pop();
            
            string str = temp.str;
            int startIdx = temp.endIdx;
            
            if (startIdx == s.length()) return true;
            if (!visited[startIdx]) {
                visited[startIdx] = true;
                for (int i = 1; i <= s.length() - startIdx; i++) {
                    string temp = s.substr(startIdx, i);
                    if (uset.count(temp)) {
                        q.push(Node(temp, startIdx + i));
                    }
                }
            }
        }
        
        return false;
    }
};