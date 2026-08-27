class Solution {
public:
    bool isCloseBracket(char c) {
        return c == ')' || c == '}' || c == ']';
    }
    bool isValid(string s) {
        stack<char> open;
        for(int i = 0 ; i < s.size() ; i++) {
            if(isCloseBracket(s[i])) {
                if(open.empty()) {
                    return false;
                }
                else {
                    char openBracket = open.top();
                    if((openBracket != '(' && s[i] == ')') ||
                    (openBracket != '{' && s[i] == '}') ||
                    (openBracket != '[' && s[i] == ']')) {
                        return false;
                    }
                    open.pop();
                }
            }
            else {
                open.push(s[i]);
            }
        }
        return open.empty();
    }
};
