class Solution {
public:
    int maxDepth(string s) {
        int res{};
        int count{};
        for (const char ch : s) {
            if (ch == '(') ++count;
            else if (ch == ')') {
                res = std::max(res, count--);
            }
        }
        return res;
    }
};
