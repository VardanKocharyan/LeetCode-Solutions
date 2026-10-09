class Solution {
public:
    int minInsertions(string s) {
        int32_t res{};
        int32_t open{};

        for (const char ch : s) {
            if (ch == '(') {
                if (open & 1) {
                    ++res;
                    --open;
                }
                open += 2;
            } else {
                --open;
                if (open == -1) {
                    ++res;
                    open += 2;
                }
            }
        }
        return res + open;
    }
};
