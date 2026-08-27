class Solution {
public:
    bool isCloseBracket(char c) {
        return c == ')' || c == '}' || c == ']';
    }
    bool isValid(string s) {
        stack<char> open;
        for(char c : s) {
            if(isCloseBracket(c)) {
                if(open.empty()) {
                    return false;
                }
                else {
                    char openBracket = open.top();
                    if((openBracket != '(' && c == ')') ||
                    (openBracket != '{' && c == '}') ||
                    (openBracket != '[' && c == ']')) {
                        return false;
                    }
                    open.pop();
                }
            }
            else {
                open.push(c);
            }
        }
        return open.empty();
    }
};
