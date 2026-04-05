class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mostWater = 0;
        int l = 0, r = heights.size() - 1;
        while(l < r) {
            if(heights[l] >= heights[r]) {
                mostWater = max(mostWater, heights[r] * (r - l));
                r--;
            }
            else {
                mostWater = max(mostWater, heights[l] * (r - l));
                l++;
            }
        }
        return mostWater;
    }
};
