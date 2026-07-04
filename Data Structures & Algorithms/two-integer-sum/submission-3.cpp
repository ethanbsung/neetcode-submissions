class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if (map.find(comp) != map.end()) {
                return {min(i, map[comp]), max(i, map[comp])};
            }
            map[nums[i]] = i;
        }
    }
};

/*
    loop through nums
    Add num in nums to a hash map along with its index
    if num + (number in the hash map) == target, return {min(i, j), max(i, j)}
    if (target - num) exists in the map, we return the index of num and index of value in the map
*/