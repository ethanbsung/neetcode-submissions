class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int res = nums[l];

        while (l <= r) {
            if (nums[l] <= nums[r]) {
                res = min(res, nums[l]);
            }
            int m = (l + r) / 2;
            if (nums[m] < nums[r]) {
                res = min(res, nums[m]);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return res;
    }
};
