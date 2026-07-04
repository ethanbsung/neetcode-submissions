class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = piles[0];
        int l = 1;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > r) r = piles[i];
        }
        int res = r;

        while (l <= r) {
            int m = l + ((r - l) / 2);
            int t = 0;
            for (int i = 0; i < piles.size(); i++) {
                t += ceil(static_cast<double>(piles[i]) / m);
            }
            if (t <= h) {
                res = min(res, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};
