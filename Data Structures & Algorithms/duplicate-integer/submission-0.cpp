class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int x: nums) {
            if (map.contains(x)) {
                return true;
            } else {
                map[x] = 1;
            }
        }
        return false;
    }
};