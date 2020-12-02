// O(log(m) + log(n))

class Solution {
public:
    int binarySearchH (vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        int mid = (left + right) / 2;
        while (arr[mid] != target) {
            if (left == mid) {
                if (arr[right] == target)
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
    
    int binarySearchV (vector<vector<int>>& arr, int target, int index) {
        int left = 0, right = arr.size() - 1;
        int mid = (left + right) / 2;
        while (arr[mid][index] != target) {
            if (left == mid) {
                if (arr[right][index] == target)
                    return right;
                return right;
            }
            else if (arr[mid][index] < target) {
                left = mid;
            }
            else {
                right = mid;
            }
            mid = (left + right) / 2;
        }
        
        return mid;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target, int row, int col) {
        int val = matrix[row][col];
        if (val == target) {
            return true;
        }
        else if (val < target) {
            int _row = binarySearchV(matrix, target, col);
            if (row == _row) return false;
            return searchMatrix(matrix, target, _row, col);
        }
        else {
            int _col = binarySearchH(matrix[row], target);
            if (col == _col) return false;
            return searchMatrix(matrix, target, row, _col);
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix(matrix, target, 0, matrix[0].size() - 1);
    }
};

