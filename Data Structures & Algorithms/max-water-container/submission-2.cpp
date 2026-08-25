class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        int maxWater = 0;
        while(l < r) {
            int currentWater = min(heights[l], heights[r])*(r - l);
            maxWater = max(maxWater, currentWater);
            if(heights[l] >= heights[r]) {
                r--;
            }
            else {
                l++;
            }
        }
        return maxWater;
    }
};
