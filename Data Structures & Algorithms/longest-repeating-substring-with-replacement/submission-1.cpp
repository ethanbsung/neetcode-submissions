class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int res = 0;
        int maxf = 0;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            count[s[r]] += 1;
            maxf = max(maxf, count[s[r]]);
            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l += 1;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
