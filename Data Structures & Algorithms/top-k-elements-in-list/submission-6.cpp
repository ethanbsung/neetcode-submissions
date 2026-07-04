class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numMap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res;

        for (auto& num : nums) {
            numMap[num] += 1;
        }

        for (auto& [key, val] : numMap) {
            pq.push({val, key});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        for (int i = 0; i < k; i++) {
            int x = pq.top().second;
            pq.pop();
            res.push_back(x);
        }
        return res;
    }
};
