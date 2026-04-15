class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max{INT_MIN}, sum{}, carry{};
        int n = nums.size();

        for (int i{}; i < n; ++i) {
            carry += nums[i];
          
            if (max < carry) max = carry;
            
            if (carry <= 0) {
                carry = 0;
                continue;
            }

            
        }

        return max;
        
    }
};
