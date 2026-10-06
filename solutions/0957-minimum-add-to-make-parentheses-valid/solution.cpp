class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans{};
        int open{};
        for (const char ch : s) {
            if (ch == '(') ++open;
            else {
                --open;
                if (open < 0) {
                    ans -= open;
                    open = 0;
                }
            }
        }
        return ans + open;
    }
};
