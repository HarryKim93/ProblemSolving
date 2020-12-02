// O(m * log(n)) using binary Search

class Solution {
public:
    int binarySearchH (vector<int>& arr, int target, int limit) {
        int left = 0, right = limit;
        int mid = (left + right) / 2;
        while (arr[mid] != target) {
            if (left == mid) {
                if (arr[mid] == target)
                    return right;
                return left;
            }
            else if (arr[mid] < target) {
                left = mid;
            }
            else {
                right = mid;
            }
            mid = (left + right) / 2;
        }
        
        return mid;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int limitH = matrix[0].size() - 1;
        
        for (int i = 0; i < matrix.size(); i++) {
            limitH = binarySearchH(matrix[i], target, limitH + 1);
            if (matrix[i][limitH] == target) return true;
            //if (matrix[i][binarySearchH(matrix[i], target, limitH + 1)] == target) return true;
        }
        return false;
    }
};