class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int l = 0;
        int r = l + 1;
        while (l < nums.size() && r < nums.size()) {
            while (nums[l] != 0 && l < nums.size() - 1) {
                l++;
            }
            while ((nums[r] == 0 || r < l) && r < nums.size() - 1) {
                r++;
            }
            if(nums[r] == 0 || nums[l] != 0) return;
            while (nums[l] == 0) {
                nums[l] = nums[r];
                nums[r] = 0;
                l++;
                while (nums[r] == 0 && r < nums.size() - 1) {
                    r++;
                }
                if(nums[r] == 0) return;
            }
        }
    }
};