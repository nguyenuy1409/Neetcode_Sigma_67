class Solution {
public:
    unordered_map<char, string> keyboard = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void backtrack(string& digits, vector<string>& res, string& currAns, int index) {
        if(currAns.size() == digits.size()) {
            res.push_back(currAns);
        }
        for(const char& c : keyboard[digits[index]]) {
            currAns += c;
            backtrack(digits, res, currAns, index + 1);
            currAns.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        string currAns = "";
        vector<string> res;
        backtrack(digits, res, currAns, 0);
        return res;
    }
};
