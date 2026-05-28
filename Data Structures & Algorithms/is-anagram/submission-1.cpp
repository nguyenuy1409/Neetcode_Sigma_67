class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int freq[26] = {0};
        int ptr = 0;
        while(ptr < s.size()) {
            freq[s[ptr] - 'a']++;
            freq[t[ptr] - 'a']--;
            ptr++;
        }
        for(const int& f : freq) {
            if(f != 0) return false;
        }
        return true;
    }
};
