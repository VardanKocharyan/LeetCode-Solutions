class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        std::vector<int> odd_leaters(58, 0);

        for (int i{}; i < n; ++i) {
            ++odd_leaters[s[i] - 'A'];
        }

        int count{};
        for (int i{}; i < 58; ++i) {
            odd_leaters[i] %= 2;
            if (odd_leaters[i]) ++count;
        }

        if (count) {
            return n - count + 1;
        }
            
        return n;
    }
};
