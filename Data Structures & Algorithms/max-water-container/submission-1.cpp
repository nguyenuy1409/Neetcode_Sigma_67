class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        int maxWater = 0;
        while(l < r) {
            int currentArea = min(heights[l], heights[r])*(r - l);
            if(heights[l] >= heights[r]) {
                maxWater = max(maxWater, heights[r]*(r - l));
                r--;
            }
            else {
                maxWater = max(maxWater, heights[l]*(r - l));
                l++;
            }
        }
        return maxWater;
    }
};
