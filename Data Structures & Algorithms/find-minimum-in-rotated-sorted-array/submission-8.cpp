class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int res = nums[l];

        while (l <= r) {
            int m = (l + r) / 2;
            res = min(res, nums[m]);
            if (nums[m] >= nums[l]) {
                res = min(res, nums[l]);
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return res;
    }
};
