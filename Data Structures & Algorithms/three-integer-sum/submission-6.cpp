class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0 ; i < n - 2 ; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;
            int target = -nums[i];
            while(l < r) {
                int sum = nums[l] + nums[r];
                if(sum == target) {
                    res.push_back({nums[i], nums[l], nums[r]});

                    while(l < r && nums[l] == nums[l + 1]) l++;
                    while(l < r && nums[r] == nums[r - 1]) r--;

                    l++; r--;
                }
                else if(sum < target) l++;
                else r--;
            }
        }
        return res;
    }
};
