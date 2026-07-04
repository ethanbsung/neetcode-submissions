class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int k = (r + l) / 2;
            int t = 0;
            for (auto& p : piles) {
                t += ceil((static_cast<double>(p) / k));
            }
            if (t <= h) {
                res = min(res, k);
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};
