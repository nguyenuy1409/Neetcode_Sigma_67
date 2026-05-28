class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& currAns, vector<bool>& visited) {
        if(currAns.size() == nums.size()) {
            res.push_back(currAns);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++) {
            if(!visited[i]) {
                currAns.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums, res, currAns, visited);
                currAns.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> res;
        vector<int> currAns;
        backtrack(nums, res, currAns, visited);
        return res;
    }
};
