class Solution {
public:
    int countCommas(int n) {
        return (n >= 1e3) ? (n - 999) : 0;
    }
};
