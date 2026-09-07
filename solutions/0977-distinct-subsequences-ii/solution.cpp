class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        std::vector<int> vis(26, 0);
        int prev{};

        for (int i = s.length() - 1; i >= 0; --i) {
            int now = (prev + 1 - vis[s[i] - 'a'] + MOD) % MOD;

            prev = (prev + now) % MOD;
            vis[s[i] - 'a'] = (vis[s[i] - 'a'] + now) % MOD;

        }

        return prev;
    }
};
