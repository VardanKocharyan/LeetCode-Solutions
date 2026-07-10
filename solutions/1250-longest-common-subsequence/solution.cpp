class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        std::vector<int> dp(m + 1, 0);
        
        for (int i{}; i < n; ++i) {
            int tmp{};       
            for (int j{}; j < m; ++j) {
                int t = dp[j + 1];
                if (text1[i] == text2[j]) dp[j + 1] = 1 + tmp;
                else dp[j + 1] = std::max(dp[j], dp[j + 1]);
                tmp = t;
            }
        }
        return dp[m];
    }
};
