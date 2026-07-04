class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1;
        for (int i = 0; i < matrix.size() - 1; ++i) {
            if (matrix[i][0] == target) return true;
            if (matrix[i+1][0] == target) return true;
            if (((matrix[i][0]) < target) && (matrix[i+1][0] > target)) {
                row = i;
                break;
            }
        }
        for (int j = 0; j < matrix[row].size(); ++j) {
            if (matrix[row][j] == target) return true;
        }
        return false;
    }
};
