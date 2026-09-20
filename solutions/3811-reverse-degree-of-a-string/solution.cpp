class Solution {
public:
    int reverseDegree(string s) {
        int res{};
        for (int i{}; i < s.length(); ++i) {
            res += (i + 1) * (123 - s[i]);
        }
        return res;
    }
};
