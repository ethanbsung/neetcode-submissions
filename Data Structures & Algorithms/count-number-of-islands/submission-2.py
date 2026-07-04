class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        islands = 0
        ROWS = len(grid)
        COLS = len(grid[0])
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        def bfs(r, c):
            q = deque()
            grid[r][c] = "0"
            q.append((r, c))

            while q:
                row, col = q.popleft()
                for dr, dc in directions:
                    ro, co = row + dr, col + dc
                    if (ro < 0 or co < 0 or ro >= ROWS or co >= COLS or grid[ro][co] == "0"):
                        continue
                    grid[ro][co] = "0"
                    q.append((ro, co))

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == "1":
                    bfs(r, c)
                    islands += 1
        

        return islands