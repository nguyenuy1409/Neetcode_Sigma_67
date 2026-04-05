class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_step = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(max_step < i) {
                return false;
            }
            max_step = max(max_step, i + nums[i]);
            
            // Early exit
            if(max_step > nums.size() - 1) return true;
        }
        return true;
    }
};
