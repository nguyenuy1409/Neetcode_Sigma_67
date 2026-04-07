class Solution {
public:
    std::unordered_map<char, std::string> keyboard = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void backtrack(std::string& digits, std::string& currAns, std::vector<std::string>& res, int index) {
        if(index == digits.size()) {
            res.push_back(currAns);
            return;
        }
        for(const auto& key : keyboard[digits[index]]) {
            currAns+=key;
            backtrack(digits, currAns, res, index + 1);
            currAns.pop_back();
        }
    }
    std::vector<std::string> letterCombinations(string& digits) {
        if(digits.size() == 0) return {};
        std::vector<std::string> res;
        std::string currAns = "";
        backtrack(digits, currAns, res, 0);
        return res;
    }
};
