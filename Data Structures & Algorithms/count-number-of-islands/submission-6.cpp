class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1') {
                    dfs(r, c, ROWS, COLS, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
private:
    int islands = 0;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    

    void dfs(int r, int c, int ROWS, int COLS, vector<vector<char>>& grid) {
            queue<pair<int, int>> q;
            grid[r][c] = '0';
            q.push({r, c});

            while (!q.empty()) {
                auto [row, col] = q.front();
                q.pop();

                for (auto& dir : directions) {
                    int nr = row + dir.first;
                    int nc = col + dir.second;
                    if (nr < 0 || nr >= ROWS || nc >= COLS || nc < 0 || grid[nr][nc] == '0') {
                        continue;
                    } else {
                        grid[nr][nc] = '0';
                        q.push({nr, nc});      
                    }
                }
            }
        }
};
