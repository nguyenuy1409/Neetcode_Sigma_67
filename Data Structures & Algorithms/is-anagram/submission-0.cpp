class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int word[26] = {0};
        int ptr = 0;
        while(ptr < s.size()) {
            word[s[ptr] - 'a']++;
            word[t[ptr] - 'a']--;
            ptr++;
        }
        for(const int& w : word) {
            if(w != 0) return false;
        }
        return true;
    }
};
