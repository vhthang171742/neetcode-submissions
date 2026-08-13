class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;

        for (int i = 0; i < s.length(); i++) {
            if (smap.contains(s[i])) {
                smap[s[i]]++;
            } else {
                smap[s[i]] = 1;
            }
            if (tmap.contains(t[i])) {
                tmap[t[i]]++;
            } else {
                tmap[t[i]] = 1;
            }
        }

        for (auto& [ key, value ] : smap) {
            if (tmap[key] != value) return false;
        }

        return true;
    }
};
