class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;

        int b{}, a = 1;
        for (int i{2}; i <= n; ++i) {
            a = a + b;
            b = a - b;
        }
        return a;
    }
};
