class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numMap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> res;
        vector<int> out;

        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]] += 1;
        }

        for (auto& [key, val] : numMap) {
            res.push({val, key});
            if (res.size() > k) {
                res.pop();
            }
        }

        for (int i = 0; i < k; i++) {
            int x = res.top().second;
            res.pop();
            out.push_back(x);
        }

        return out;
    }
};
