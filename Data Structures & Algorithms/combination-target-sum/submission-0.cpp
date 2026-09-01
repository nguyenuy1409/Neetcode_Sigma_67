class Solution {
public:
    void backtrack(int startIndex, vector<int>& currAns, vector<vector<int>>& res, vector<int>& nums, int currSum, int target) {
        if(currSum == target) {
            res.push_back(currAns);
            return;
        }
        for(size_t i = startIndex ; i < nums.size() ; i++) {
            if(currSum + nums[i] > target) {
                break;
            }
            currAns.push_back(nums[i]);
            currSum+=nums[i];
            backtrack(i, currAns, res, nums, currSum, target);
            currAns.pop_back();
            currSum-=nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> currAns;
        backtrack(0, currAns, res, nums, 0, target);
        return res;
    }
};
