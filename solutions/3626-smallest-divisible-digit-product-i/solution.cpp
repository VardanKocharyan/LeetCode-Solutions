class Solution {
public:
    bool isValid(int n, int t) {
        int product{1};
        while (n) {
            product *= n % 10;
            n /= 10;
        }
        return product % t;
    }

    int smallestNumber(int n, int t) {
        while (isValid(n, t)) {
            ++n;
        }
        return n;
    }
};
