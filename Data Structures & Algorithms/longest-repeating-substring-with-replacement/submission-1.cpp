class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int left = 0, maxLength = 0, maxFreq = 0;
        for(int right = 0 ; right < s.size() ; right++) {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);
            if((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }
            else {
                maxLength = max(maxLength, right - left + 1);
            }
        }
        return maxLength;
    }
};
