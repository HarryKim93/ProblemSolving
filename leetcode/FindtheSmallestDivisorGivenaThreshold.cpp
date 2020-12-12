// O(logN)

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e6;
        int mid = (left + right) / 2;
        int sum = 0;
        
        while (left < right) {
            sum = 0;
            for (auto num : nums) {
                sum += ((num + mid - 1) / mid);
            }

            if (sum > threshold) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
            mid = (left + right) / 2;
        }
        
        return left;
    }
};