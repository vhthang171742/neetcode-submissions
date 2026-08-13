class Solution {
   public:
    bool isPalindrome(string s) {
        int len = s.length();
        int r = len - 1;
        for (int i = 0; i < len / 2; i++) {
            while (!isAlphaNumeric(s[i])) i++;
            while (!isAlphaNumeric(s[r])) r--;
            if (r <= i) return true;

            if (tolower(s[i]) != tolower(s[r])) return false;
            r--;
        }
        return true;
    }

    bool isAlphaNumeric(char &c) {
        return (int(c) >= '0' && int(c) <= '9') || (int(c) >= 'a' && int(c) <= 'z')|| (int(c) >= 'A' && int(c) <= 'Z');
    }
};
