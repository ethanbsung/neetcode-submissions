class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while (l <= r) {
            while (l < r && !isNum(s[l])) {
                ++l;
            }  
            while (l < r && !isNum(s[r])) {
                --r;
            }
            if (tolower(s[l]) != tolower(s[r])) return false;
            r--;
            l++;
        }
        return true;
    }

    bool isNum(char c) {
        return c >= 'a' && c <= 'z' ||
                c >= 'A' && c <= 'Z' ||
                c >= '0' && c <= '9';
    }
};
