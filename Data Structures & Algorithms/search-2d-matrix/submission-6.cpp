class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = 0;
        int n = matrix.size() - 1;

        while (m < n) {
            int mid = m + ((n - m) / 2);

            if (matrix[mid][0] > target) {
                n = mid - 1;
            } else if (matrix[mid][0] < target) {
                if (matrix[mid][matrix[mid].size() - 1] >= target) {
                    m = mid;
                    break;
                }
                m = mid + 1;
            } else {
                m = mid;
                break;
            }
        }

        int l = 0;
        int r = matrix[m].size() - 1;

        while (l <= r) {
            int mid = l + ((r - l) / 2);

            if (matrix[m][mid] > target) {
                r = mid - 1;
            } else if (matrix[m][mid] < target) {
                l = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
