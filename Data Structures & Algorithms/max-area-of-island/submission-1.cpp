class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    maxArea = max(maxArea, bfs(grid, r, c, ROWS, COLS));
                }
            }
        }

        return maxArea;
    }

    int bfs(vector<vector<int>>& grid, int r, int c, int ROWS, int COLS) {
        int area = 1;
        queue<pair<int, int>> q;
        grid[r][c] = 0;
        q.push({r, c});

        while (!q.empty()) {
            auto& [row, col] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int nr = row + dir[0];
                int nc = col + dir[1];
                if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || grid[nr][nc] == 0) {
                    continue;
                } else {
                    area++;
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                }
            }
        }

        return area;
    }

    
    int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
};
