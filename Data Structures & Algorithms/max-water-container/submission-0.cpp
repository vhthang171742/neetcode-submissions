class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        tuple<int, int, int> biggestContainer = make_tuple(l, r, calcArea(heights, l, r));
        while (l < r) {
            if (heights[l] < heights[r])
                l++;
            else
                r--;
            if (l == r) break;

            int area = calcArea(heights, l, r);

            if (area > get<2>(biggestContainer)) {
                get<0>(biggestContainer) = l;
                get<1>(biggestContainer) = r;
                get<2>(biggestContainer) = area;
            }
        }

        return get<2>(biggestContainer);
    }

    int calcArea(vector<int>& heights, int l, int r) {
        return (r - l) * min(heights[r], heights[l]);
    }
};
