class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> intMap;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            auto it = intMap.find(diff);
            if (it != intMap.end()) {
                return {it->second, i};
            }
            intMap[nums[i]] = i;
        }
    }
};
