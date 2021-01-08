// O(WORD1 * WORD2)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.length() + 1][word2.length() + 1];
        for (int i = 0; i <= word1.length(); i++) for (int j = 0; j <= word2.length(); j++) dp[i][j] = INT_MAX;
    
        function <int(int, int, int)> func = [&](int idx1, int idx2, int oper) -> int {
            int ans = INT_MAX;
            
            if (idx1 == word1.length() && idx2 == word2.length()){
                return oper;
            } else {
                if (dp[idx1][idx2] > oper) {
                    if (word1[idx1] == word2[idx2]) {
                        return func(idx1 + 1, idx2 + 1, oper);
                    } else {
                        //insert
                        if (idx2 < word2.length())
                            ans = func(idx1, idx2 + 1, oper + 1);
                        //delete
                        if (idx1 < word1.length())
                            ans = min<int>(ans, func(idx1 + 1, idx2, oper + 1));
                        //modify
                        if (idx1 < word1.length() && idx2 < word2.length())
                            ans = min<int>(ans, func(idx1 + 1, idx2 + 1, oper + 1));
                    }
                }
            }
            
            dp[idx1][idx2] = oper;
            return ans;
        };
    }
        
        struct node {
            int idx1, idx2;
            int oper;
            node(int _idx1, int _idx2, int_oper) : idx1(_idx1), idx2(_idx2), oper(_oper) {}
        };
        
        queue<node> q;
        int idx1, idx2, oper;
        while (!q.empty()) {
            node _node = q.front();
            q.pop();
            
            idx1 = _node.idx1;
            idx2 = _node.idx2;
            oper = _node.oper;
            
            if (idx1 == word1.length() && idx2 == word2.length()) return _node.oper;
            else {
                if (word1[idx1] == word2[idx2]) {
                    
                }
            }
        }
        
        return func(0, 0, 0);
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() == 0) return word2.length();
        if (word2.length() == 0) return word1.length();
        
        int dp[word1.length() + 1][word2.length() + 1];
        for (int i = 0; i <= word1.length(); i++) for (int j = 0; j <= word2.length(); j++) dp[i][j] = INT_MAX - 1;

        int word1Len = word1.length(), word2Len = word2.length();
        
        dp[0][0] = 0;
        bool check = true;
        
        for (int i = 0; i < word1Len; i++) {
            for (int j = 0; j < word2Len; j++) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = min<int>(dp[i + 1][j + 1], dp[i][j]);
                } else {
                    dp[i + 1][j] = min<int>(dp[i + 1][j], dp[i][j] + 1);
                    dp[i][j + 1] = min<int>(dp[i][j + 1], dp[i][j] + 1);
                    dp[i + 1][j + 1] = min<int>(dp[i + 1][j + 1], dp[i][j] + 1);
                }
            }
        }
        
        for (int i = 0; i < word1Len; i++) {
            if (dp[i][word2.length()] == INT_MAX - 1) continue;
            dp[word1.length()][word2.length()] = min<int>(dp[word1.length()][word2.length()], dp[i][word2.length()] + (word1.length() - i));
        }
        for (int j = 0; j < word2Len; j++) {
            if (dp[word1.length()][j] == INT_MAX - 1) continue;
            dp[word1.length()][word2.length()] = min<int>(dp[word1.length()][word2.length()], dp[word1.length()][j] + (word2.length() - j));
        }
        
        return dp[word1.length()][word2.length()];
    }
};