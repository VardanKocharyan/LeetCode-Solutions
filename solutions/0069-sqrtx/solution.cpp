class Solution {
public:
    int mySqrt(int x) {
        int l{1}, r = x;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (m == x / m) return m;
            else if (m > x / m) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (l > x / l) l -= 1;

        return l;
    }
};
