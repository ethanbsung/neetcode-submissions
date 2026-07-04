class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;

        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            mapS[s[i]] += 1;
            mapT[t[i]] += 1;
        }

        return (mapS == mapT);
    }
};

/*
    We want to keep track of how many times each character has been seen
    Use a hash map
    If the maps are the same, return true, else false
*/