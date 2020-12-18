// https://leetcode.com/problems/third-maximum-number/
// O(N)

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long one= LLONG_MIN, two = LLONG_MIN, three = LLONG_MIN;
        
        for (auto num : nums) {
            if (num > one) {
                three = two;
                two = one;
                one = num;
            } else if (num < one && num > two) {
                three = two;
                two = num;
            } else if (num < two && num > three) {
                three = num;
            }
        }
        
        int ione = one, itwo = two, ithree = three;
        return three == LLONG_MIN ? ione : ithree;
    }
};