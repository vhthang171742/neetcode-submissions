class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, ArrayHash> res;
        for (int i = 0; i < strs.size(); i++) {
            unordered_map<char, int> freq;
            for (char c : strs[i]) {
                if (freq.contains(c))
                    freq[c]++;
                else
                    freq[c] = 1;
            }
            array<int, 26> freqArray{};
            for (auto& [key, value] : freq) {
                freqArray[charIndex(key)] = value;
            }

            res[freqArray].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (auto& [k, v] : res) {
            result.push_back(v);
        }
        return result;
    }

    int charIndex(char c) { return int(c) - int('a'); }

    struct ArrayHash {
        size_t operator()(const array<int, 26>& a) const {
            size_t h = 0;

            for (int x : a) {
                h = h * 31 + x;
            }

            return h;
        }
    };
};
