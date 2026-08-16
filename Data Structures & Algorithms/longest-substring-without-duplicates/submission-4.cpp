class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();

        int l = 0;
        int r = 1;
        int maxLen = 1;
        unordered_map<char, int> subStr;
        subStr[s[0]] = 0;
        while (r < s.length()) {
            if (subStr.contains(s[r]) && subStr[s[r]] >= l) {
                l = subStr[s[r]] + 1;
                subStr[s[r]] = r;
                r++;
            } else {
                subStr[s[r]] = r;
                r++;
                maxLen = max(maxLen, r - l);
            }
        }

        return maxLen;
    }
};
