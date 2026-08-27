class Solution {
public:

    // DFS function
    int dfs(vector<vector<int>>& grid, int r, int c) {

        int rows = grid.size();
        int cols = grid[0].size();

        // If out of bounds or water
        if(r < 0 || c < 0 || r >= rows || c >= cols ||
           grid[r][c] == 0) {
            return 0;
        }

        // Mark cell as visited
        grid[r][c] = 0;

        // Current cell contributes 1 to area
        int area = 1;

        // 4 possible directions
        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // Visit all 4 directions
        for(int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            area += dfs(grid, nr, nc);
        }

        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        // Store maximum island area
        int maxArea = 0;

        // Traverse the entire grid
        for(int r = 0; r < rows; r++) {

            for(int c = 0; c < cols; c++) {

                // If we find land
                if(grid[r][c] == 1) {

                    // Find area of this island
                    int area = dfs(grid, r, c);

                    // Update maximum area
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
