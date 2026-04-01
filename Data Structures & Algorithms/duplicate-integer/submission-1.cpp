class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> duplicateCheck;
        for(const int& n : nums) {
            if(duplicateCheck.count(n)) {
                return true;
            }
            duplicateCheck.insert(n);
        }
        return false;
    }
};