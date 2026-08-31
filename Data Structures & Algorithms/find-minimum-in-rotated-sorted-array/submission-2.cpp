class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int minVal = 1000;
        while(l <= r) {
            int m = l + (r - l)/2;
            if(nums[l] < nums[r]) {
                if(nums[m] > nums[l]) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            else {
                if(nums[m] > nums[r]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;;
                }
            }
            minVal = min(minVal, nums[m]);
        }
        return minVal;
    }
};
