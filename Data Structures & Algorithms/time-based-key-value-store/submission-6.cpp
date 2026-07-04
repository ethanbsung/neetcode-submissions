class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {    
        int l = 0;
        int r = timeMap[key].size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (timeMap[key][m].second == timestamp || (timeMap[key][m].second < timestamp && timeMap[key][m+1].second > timestamp) || (timeMap[key][m].second <= timestamp && m == timeMap[key].size() - 1)) {
                return timeMap[key][m].first;
            }
            else if (timeMap[key][m].second > timestamp) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return "";
    }
private:
    unordered_map<string, vector<pair<string, int>>> timeMap;
};
