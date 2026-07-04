class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        unordered_map<char, int> count1;
        unordered_map<char, int> count2;

        for (int i = 0; i < s1.length(); i++) {
            count1[s1[i]]++;
        }

        for (int r = 0; r < s2.length(); r++) {
            count2[s2[r]]++;
            while (r - l + 1 > s1.length()) {
                count2[s2[l]]--;
                if (count2[s2[l]] == 0) count2.erase(s2[l]);
                l++;
            }

            if (count2 == count1) return true;
        }

        return false;
    }
};
