class Solution {
public:
int8_t isValid(int i, std::string_view s) { 
    if (s[i] == '0') return 0; 
    return (i + 1 < s.length() && s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) + 1;
}
    
    int32_t solve(int i, std::string_view s, std::vector<int32_t>& dp) {
        if (i == s.length()) return 1;
        if (i > s.length()) return 0;
        if (dp[i] != -1) return dp[i];

        switch(isValid(i, s)) {
            case 0:
                dp[i] = 0; 
                break;
            case 1:
                dp[i] = solve(i + 1, s, dp);
                break;
            default:
                dp[i] = solve(i + 1, s, dp) + solve(i + 2, s, dp);;
        }
        return dp[i];
    }

    int numDecodings(string s) {
        const int n = static_cast<int>(s.length());
        std::vector<int32_t> dp(n, -1);
        return solve(0, s, dp);
    }
};
