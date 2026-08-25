class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0 ; i < n - 2 ; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while(l < r) {
                int target = -nums[i];
                if(nums[l] + nums[r] == target) {
                    result.push_back({nums[i], nums[l], nums[r]});

                    while(l < r && nums[l] == nums[l + 1]) l++;
                    while(l < r && nums[r] == nums[r - 1]) r--;
                    l++; r--;
                }
                else if(nums[l] + nums[r] < target) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return result;
    }
};
