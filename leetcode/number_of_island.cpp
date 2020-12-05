class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ud[4] = {0, 0, 1, -1};
        int rl[4] = {1, -1, 0, 0};
        
        function<void(int, int)> func = [&](int row, int col) -> void{
            visited[row][col] = true;
            
            for(int i = 0; i < 4; i++) {
                int _row = row + ud[i];
                int _col = col + rl[i];
                
                if (_row < 0 || _row >= grid.size() || _col < 0 || _col >= grid[0].size()) continue;
                if (visited[_row][_col]) continue;
                if (grid[_row][_col] == '0') continue;
                
                func(_row, _col);
            }
        };
        
        int ans = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != '0' && !visited[i][j]) {
                    func(i, j);
                    ans++;    
                }
            }
        }
        
        return ans;
    }
};