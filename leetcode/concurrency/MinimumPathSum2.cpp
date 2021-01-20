// O(N * N)

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i - 1 >= 0 && j - 1 >= 0) {
					grid[i][j] = grid[i][j] + min<int>(grid[i - 1][j], grid[i][j - 1]);
				} else if (i - 1 >= 0) {
					grid[i][j] = grid[i][j] + grid[i - 1][j];
				} else if (j - 1 >= 0) {
					grid[i][j] = grid[i][j] + grid[i][j - 1];
				} else {
					continue;
				}
			}
		}

		return grid[m - 1][n - 1];
	}
};