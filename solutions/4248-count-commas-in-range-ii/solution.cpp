class Solution {
public:
    long long countCommas(long long n) {        
        long long res{};
        for (long long i{1000}; i <= n; i *= 1000) res += n - i + 1;
        return res;
    }
};

// 1e3  1e6  1e9   1e12   1e15
