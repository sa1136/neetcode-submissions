
class Solution {
public:
    // DFS helper: explores backward from an ocean, marking every cell
    // that could flow INTO that ocean. Moves to a neighbor if the neighbor's
    // height is >= current height (reverse of the real downhill flow direction).
    // Time complexity: O(m*n) per full traversal, Space: O(m*n) recursion stack
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        int rows = heights.size();
        int cols = heights[0].size();

        visited[r][c] = true;   // mark: this cell can reach this ocean

        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // boundary check + not yet visited + uphill-or-equal (reverse flow)
            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols &&
                !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(heights, visited, nr, nc);
            }
        }
    }

    // Runs two independent flood fills — one from each ocean's border cells —
    // then returns every cell present in both resulting visited sets.
    // Time complexity: O(m*n) total, Space complexity: O(m*n) for visited grids
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // Pacific touches top row and left column
        for (int c = 0; c < cols; c++) dfs(heights, pacific, 0, c);
        for (int r = 0; r < rows; r++) dfs(heights, pacific, r, 0);

        // Atlantic touches bottom row and right column
        for (int c = 0; c < cols; c++) dfs(heights, atlantic, rows - 1, c);
        for (int r = 0; r < rows; r++) dfs(heights, atlantic, r, cols - 1);

        // A cell qualifies only if it's reachable from BOTH oceans
        vector<vector<int>> result;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};