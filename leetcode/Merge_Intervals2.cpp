// https://leetcode.com/problems/merge-intervals/
// O(N * log(N))

#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0 && x != 0) return false;
        int y = 0;

        while (y < x) {
            y = y*10 + (x % 10);
            x  = x / 10;
        }
     
        return x == y || y / 10 == x;
    } 
};