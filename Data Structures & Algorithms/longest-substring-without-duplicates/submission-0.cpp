class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        unordered_set<char> seen;
        int maxLength = 0;
        int slow = 0, fast = 0;
        while(fast < s.size()) {
            while(seen.count(s[fast])) {
                seen.erase(s[slow]);
                slow++;
            }
            seen.insert(s[fast]);
            maxLength = max(maxLength, fast - slow + 1);
            fast++;
        }
        return maxLength;
    }
};
