class Solution {
public:
    template <class InputIt1, class InputIt2>
    bool ValidWord(InputIt1 src, InputIt2 begin, InputIt2 end) {
        while (begin != end) {
            if (*begin != *src) return false;
            ++src;
            ++begin;
        }
        return true;
    }

    int solve(int pos, std::string& s, std::vector<std::string>& w, std::vector<int>& dp) {
        if (pos >= s.length()) return 1;
        if (dp[pos] != -1) return dp[pos];

        for (int word{}; word < w.size(); ++word) {

            if (s.length() - pos < w[word].length()) {
                continue;    
            } else if (ValidWord(s.begin() + pos, w[word].begin(), w[word].end()) ) {
                
                int res = solve(pos + w[word].length(), s, w, dp);
                if (res == 1) return dp[pos] = res;
            
            }
        }

        return dp[pos] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<int> dp(s.length(), -1);

        return solve(0, s, wordDict, dp);
    }
};
