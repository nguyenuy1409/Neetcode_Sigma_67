class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int l = 0;
        int longestSubstring = 0;
        for(int r = 0 ; r < (int)s.size() ; r++) {
            while(seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            longestSubstring = max(longestSubstring, r - l + 1);
        }
        return longestSubstring;
    }
};
