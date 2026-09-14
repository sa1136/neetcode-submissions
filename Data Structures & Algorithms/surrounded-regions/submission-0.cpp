class Solution {
public:

    int dr[4] = {1, 0, -1, 0};   // down, right, up, left
    int dc[4] = {0, 1, 0, -1};

    void dfs(vector<vector<char>>& board, int r, int c) {

        int m = board.size();
        int n = board[0].size();

        board[r][c] = '#';   // Mark boundary-connected O as safe

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            // If inside board and the cell is O, continue DFS
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                board[nr][nc] == 'O') {

                dfs(board, nr, nc);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        if (board.empty() || board[0].empty()) {
            return;
        }

        int m = board.size();
        int n = board[0].size();

        // DFS from top and bottom boundaries
        for (int c = 0; c < n; c++) {

            if (board[0][c] == 'O') {
                dfs(board, 0, c);
            }

            if (board[m - 1][c] == 'O') {
                dfs(board, m - 1, c);
            }
        }

        // DFS from left and right boundaries
        for (int r = 0; r < m; r++) {

            if (board[r][0] == 'O') {
                dfs(board, r, 0);
            }

            if (board[r][n - 1] == 'O') {
                dfs(board, r, n - 1);
            }
        }

        // Capture surrounded O's and restore safe O's
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                else if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }
    }

    // TC: O(m*n) because every cell is visited at most a constant number of times.
    // SC: O(m*n) because DFS recursion can go as deep as the number of cells.
};