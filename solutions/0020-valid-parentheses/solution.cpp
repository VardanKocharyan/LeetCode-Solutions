class Solution {
public:
    bool isValid(string s) {
        std::stack<char> ch;
        int i{};
        if (s[i] == '}' || s[i] == ']' || s[i] == ')') return false;

        while (s[i]) {
            char c = s[i];
            if (c == '{' || c == '[' || c == '(') { 
                ch.push(c); 
            } else if (!ch.empty() && ((ch.top() == '{' && c == '}') || (ch.top() == '(' && c == ')') || (ch.top() == '[' && c == ']'))) {
                ch.pop();
            } else {
                return false;
            }
            ++i;
        }
        return ch.empty();
    }
};
