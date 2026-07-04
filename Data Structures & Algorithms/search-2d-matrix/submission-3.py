class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        cols = len(matrix[0]) - 1
        rows = len(matrix) - 1
        row = 0
        l, r = 0, rows

        while l <= r:
            m = l + ((r - l) // 2)

            if matrix[m][0] <= target and matrix[m][cols] >= target:
                row = m
                break
            elif matrix[m][0] < target:
                l = m + 1
            else:
                r = m - 1
        
        l, r = 0, cols

        while l <= r:
            m = l + ((r - l) // 2)

            if matrix[row][m] > target:
                r = m - 1
            elif matrix[row][m] < target:
                l = m + 1
            else:
                return True
        
        return False