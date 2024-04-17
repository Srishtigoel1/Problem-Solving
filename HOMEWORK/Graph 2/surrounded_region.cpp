class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& vis, int delrow[], int delcol[]) {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, board, vis, delrow, delcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();    // row
        int m = board[0].size(); // column
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m)); // visited array
        for (int i = 0; i < n; i++) {
            //row
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, board, vis, delrow, delcol);
            }
            if (board[i][m - 1] == 'O' && !vis[i][m - 1]) {
                dfs(i, m - 1, board, vis, delrow, delcol);
            }
        }
        for (int i = 0; i < m; i++) {
            //col
            if (board[0][i] == 'O' && !vis[0][i]) {
                dfs(0, i, board, vis, delrow, delcol);
            }
            if (board[n-1][i] == 'O' && !vis[n-1][i]) {
                dfs(n-1, i, board, vis, delrow, delcol);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};