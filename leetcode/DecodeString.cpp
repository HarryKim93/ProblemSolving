// worst : O(N ^ 2)

class Solution {
public:    
    string decodeString(string s) {
        string ret;
        stack<char> stk;
        
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '[') {
                stk.push('[');  
            } else if (s[i] == ']') {
                if (stk.size() == 0) break;
                stk.pop();
            } else if (stk.size() == 0) {
                if (s[i] > '0' && s[i] < '9') {
                    int num = 0;
                    while (s[i] != '[') {
                        num = num * 10 + (s[i] - '0');
                        i++;
                    }

                    string temp = decodeString(s.substr(i + 1));
                    for (int i = 0; i < num; i++) ret.append(temp);
                    cout << ret << "\n";
                    continue;
                } else {
                    ret.push_back(s[i]);
                }
            }
            i++;
        }
        
        return ret;
    }
};