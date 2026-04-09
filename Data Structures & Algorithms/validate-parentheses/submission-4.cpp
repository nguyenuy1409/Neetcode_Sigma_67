class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        stack<char> open;
        for(const char& c : s) {
            if(c == '(' || c == '{' || c == '[') {
                open.push(c);
            }
            else {
                if(open.empty()) return false;
                if((c == ')' && open.top() != '(') || (c == '}' && open.top() != '{') || (c == ']' && open.top() != '[')) {
                    return false;
                }
                open.pop();
            }
        }
        return open.empty();
    }
};
