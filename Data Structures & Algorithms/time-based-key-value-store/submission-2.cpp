class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        sort(timeMap[key].begin(), timeMap[key].end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });
        
        for (auto& [val, ts] : timeMap[key]) {
            if (ts <= timestamp) return val;
        }

        return "";
    }
private:
    unordered_map<string, vector<pair<string, int>>> timeMap;
};
