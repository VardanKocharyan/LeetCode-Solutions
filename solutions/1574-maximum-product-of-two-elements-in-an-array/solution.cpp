class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int x{1}, y{1};
        
        for (const int nb : nums) {
            if (nb > x) {
                y = x;
                x = nb;
            } else if (nb > y) {
                y = nb;
            }
        }
        return (x - 1) * (y - 1);
    }
};
