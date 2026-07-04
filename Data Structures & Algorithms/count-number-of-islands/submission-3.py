class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        islands = 0
        ROWS, COLS = len(grid), len(grid[0])
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        def bfs(r, c):
            q = deque()
            q.append((r, c))
            grid[r][c] = '0'

            while q:
                nr, nc = q.popleft()
                for dr, dc in directions:
                    row, col = nr + dr, nc + dc
                    if row >= ROWS or col >= COLS or row < 0 or col < 0:
                        continue
                    if grid[row][col] == '1':
                        grid[row][col] = '0'
                        q.append((row, col))

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == '1':
                    bfs(r, c)
                    islands += 1
        
        return islands