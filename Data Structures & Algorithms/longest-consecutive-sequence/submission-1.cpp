class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            seen.insert(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            int length = 1;
            while (seen.find(nums[i] + length) != seen.end()) {
                length++;
            }
            longest = max(longest, length);
        }

        return longest;
    }
};
