class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int biggestContainer = calcArea(heights, l, r);
        while (l < r) {
            if (heights[l] < heights[r])
                l++;
            else
                r--;
            if (l == r) break;

            int area = calcArea(heights, l, r);

            if (area > biggestContainer) {
                biggestContainer = area;
            }
        }

        return biggestContainer;
    }

    int calcArea(vector<int>& heights, int l, int r) {
        return (r - l) * min(heights[r], heights[l]);
    }
};
