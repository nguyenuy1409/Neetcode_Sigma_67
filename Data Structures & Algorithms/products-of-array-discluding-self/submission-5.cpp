class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        // Pass 1: Compute prefix products (product of all elements to the left)
        for(int i = 1 ; i < n ; i++) {
            result[i] = result[i - 1]*nums[i - 1];
        }

        // Pass 2: Multiply with running suffix products (elements to the right)
        int rightSuffix = 1;
        for(int i = n - 1 ; i >= 0 ; i--) {
            result[i]*=rightSuffix;
            rightSuffix*=nums[i];
        }
        return result;
    }
};
