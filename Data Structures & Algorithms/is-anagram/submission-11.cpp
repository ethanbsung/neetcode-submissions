class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;

        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            mapS[s[i]] += 1;
            mapT[t[i]] += 1;
        }

        if (mapS != mapT) {
            return false;
        }
        else {
            return true;
        }
    }
};
