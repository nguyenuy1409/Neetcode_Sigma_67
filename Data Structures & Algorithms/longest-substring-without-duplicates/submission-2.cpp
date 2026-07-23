class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        set<int> subString;
        int l = 0;
        for(int r = 0 ; r < s.size() ; r++) {
            while(subString.count(s[r])) {
                subString.erase(s[l]);
                l++;
            }
            subString.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
