class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> ans(n + 1);
        int next_pow = 1;
        int now_pow = 0;

        for (int i{0}; i <= n; ++i) {
            if (i == next_pow) {
                ans[i] = 1;
                now_pow = next_pow;
                next_pow <<= 1;
            } else {
                ans[i] = ans[now_pow] + ans[i - now_pow];
            }
        }        
        return ans;
    }
};
