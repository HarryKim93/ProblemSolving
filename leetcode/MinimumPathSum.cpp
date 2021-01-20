// O(2^N)

class Solution {
public:
    vector<vector<int>> cache;
    int ud[2] = {0, 1};
    int rl[2] = {1, 0};
    int m, n;
    
    void minPathSum(int row, int col, int sum, vector<vector<int>>& grid) {
        if (row < 0 || row >= m || col < 0 || col >= n) return;
        else if (cache[row][col] <= sum + grid[row][col]) return;
        else {
            cache[row][col] = min<int>(cache[row][col], sum + grid[row][col]);
            for (int i = 0; i < 2; i++)
                minPathSum(row + ud[i], col + rl[i], cache[row][col], grid);
        }
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        cache = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        
        minPathSum(0, 0, 0, grid);
        return cache[m - 1][n - 1];
    }
};