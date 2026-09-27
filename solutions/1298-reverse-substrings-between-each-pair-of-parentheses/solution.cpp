class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        std::vector<int> opened;
        std::vector<int> pair(n);
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                opened.push_back(i);
            } else if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        
        std::string result = "";
        int direction = 1; 
        
        for (int curr = 0; curr < n; curr += direction) {
            if (s[curr] == '(' || s[curr] == ')') {
                curr = pair[curr];
                direction = -direction;
            } else {
                result.push_back(s[curr]);
            }
        }
        
        return result;
    }
};
