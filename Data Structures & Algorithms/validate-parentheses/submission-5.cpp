class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                open.push(s[i]);
            }
            else {
                if(open.empty()) return false;
                char op = open.top();
                if((op == '(' && s[i] == ')') || 
                op == '{' && s[i] == '}' ||
                op == '[' && s[i] == ']') {
                    open.pop();
                }
                else {
                    return false;
                }
            }
        }
        return open.empty();
    }
};
