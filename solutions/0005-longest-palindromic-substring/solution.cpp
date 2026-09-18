class Solution {
public:
    string longestPalindrome(string s) {
        const int n = static_cast<int>(s.size());
        int start{};
        int max{};

        for (int i{}; i < n; ++i) {
            int l{i};
            int r{i};

            while (l >= 0 && r <= n && s[l] == s[r]) {
                if (r - l + 1 > max) {
                    max = r - l + 1;
                    start = l;
                }
                --l;++r;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r <= n && s[l] == s[r]) {
                if (r - l + 1 > max) {
                    max = r - l + 1;
                    start = l;
                }
                --l;++r;
            }
        }

        return s.substr(start, max);
    }
};
