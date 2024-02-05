class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = countIslands(grid);

        // All zero or multiple islands
        if (islands > 1 || islands == 0) {
            return 0;
        } else {
            // Check for 1 and 2 days
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j]) {
                        grid[i][j] = 0;
                        islands = countIslands(grid);
                        grid[i][j] = 1;

                        if (islands > 1 || islands == 0)
                            return 1;
                    }
                }
            }
        }
        // If changing any single land cell to water doesn't disconnect the grid
        return 2;
    }

private:
    // DFS to find connected islands
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        int delRows[] = {1, -1, 0, 0};
        int delCols[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int newRow = row + delRows[i];
            int newCol = col + delCols[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol] && grid[newRow][newCol] == 1) {
                dfs(newRow, newCol, grid, visited);
            }
        }
    }

    // Count the number of islands in the grid
    int countIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islandCount = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    dfs(i, j, grid, visited);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
};
