class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xor_val{0};
        bool non_zero{false};

        for (const int nb : nums) {
            xor_val ^= nb;
            non_zero |= nb;
        }

        if (xor_val) return nums.size();
        else if (!xor_val && non_zero) return nums.size() - 1;
        
        return 0;
    }
};
