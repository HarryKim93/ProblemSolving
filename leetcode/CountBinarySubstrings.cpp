// https://leetcode.com/problems/count-binary-substrings/
// O(N)

class Solution {
public:
    int countBinarySubstrings(string s) {
        int z = 0, o = 0, ans = 0;
        bool current = s[0] == '0' ? false : true;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                if (current == true && z > 0) {
                    ans += z <= o ? z : o;
                    z = 0;
                }
                
                z++;
                current = false;
            }
            else {
                if (current == false && o > 0) {
                    ans += z <= o ? z : o;
                    o = 0;
                }
                
                o++;
                current = true;
            }
        }
        
        return ans;
    }
};