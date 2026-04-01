class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < n - 2 ; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            if(nums[i] > 0) break;
            int l = i + 1, r = n - 1;
            while(l < r) {
                int threeSum = nums[i] + nums[l] + nums[r];
                if(threeSum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l + 1]) l++;
                    while(l < r && nums[l] == nums[r - 1]) r--;

                    l++; r--;
                }
                else if(threeSum > 0) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return res;
    }
};
