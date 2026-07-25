class Solution {
public:
    int maxProduct(int n) {
        int x = std::max(n % 10, (n / 10) % 10);
        int y = std::min(n % 10, (n / 10) % 10);
        n /= 100;

        while (n) {
            if (n % 10 > x) {
                y = x;
                x = n % 10;
            } else if (n % 10 > y) {
                y = n % 10;
            }
            n /= 10;
        }
        return x * y;
    }
};
