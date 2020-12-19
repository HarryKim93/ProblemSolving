// https://leetcode.com/problems/remove-vowels-from-a-string/
// O(N)
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string removeVowels(string s) {
        string ans;
        char dic[26];
        memset(dic, 0, 26);
        
        dic['a' - 'a'] = 1;
        dic['e' - 'a'] = 1;
        dic['i' - 'a'] = 1;
        dic['o' - 'a'] = 1;
        dic['u' - 'a'] = 1;
        
        for (auto ch : s) {
            if (dic[ch - 'a'] == 0) ans.append(1, ch);     
        }
        
        return ans;
    }
};

int main() {
    vector<vector<int>> vec;
    vec.push_back(vector<int>{1,2});

    return 0;
}