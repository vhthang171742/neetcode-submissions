class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int l = 0;
        int r = 1;
        while (r < nums.size()) {
            if (nums[l] == 0 && nums[r] != 0) {
                nums[l] = nums[r];
                nums[r] = 0;
                
            }
            if(nums[l] != 0)
            l++;
            r++;
        }
    }
};