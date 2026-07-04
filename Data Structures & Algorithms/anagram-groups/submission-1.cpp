class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strMap;
        vector<vector<string>> res;

        for (const auto& s : strs) {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            strMap[sortedS].push_back(s);
        }
        
        for (auto& [key, val] : strMap) {
            res.push_back(val);
        }
        return res;
    }
};
