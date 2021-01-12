// O(N)
// https://leetcode.com/problems/counting-bits/submissions/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> vec(num + 1);
        for (int i = 0; i <= num; i++) 
            vec[i] = (vec[i / 2] + i % 2);
        
        return vec;
    }
};