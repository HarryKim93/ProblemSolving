// O(N)
// https://leetcode.com/problems/jewels-and-stones/

#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_set<char> uset(J.begin(), J.end());

        for (auto ch : S)
            if (uset.count(ch)) res++;
        
        return res;
    }
};