class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int countfresh = 0; //
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0}); //...row, col and time..considering 2 is beginning
                } else if (grid[i][j] == 1) {
                    countfresh++;//
                }
            }
        }
        int tm = 0;
        int rol[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = x + rol[i];
                int ncol = y + col[i];

                // Check if index is valid or not
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                     grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    grid[nrow][ncol] = 2;
                    countfresh--;
                }
            }
        }
            if (countfresh > 0) {
                return -1;
            }
            return tm;
        }
    };