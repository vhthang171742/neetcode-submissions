class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxProfit = 0;
        int lastProfit = 0;
        while (r < prices.size()) {
            if (prices[r] - prices[l] >= 0) {
                lastProfit = prices[r] - prices[l];
                maxProfit = max(lastProfit, maxProfit);
                r++;
            }
            else {
                lastProfit = prices[r] - prices[l];
                l = r;
            }
        }
        return maxProfit;
    }
};
