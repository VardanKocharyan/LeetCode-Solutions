class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum1{};
        int sum2{};

        if (nums.size() == 1) return 0;

        for (int i{1}; i < nums.size(); ++i) {
            sum2 += nums[i];
        }

        for (int i{1}; i < nums.size(); ++i) {
            if (sum1 == sum2) return i - 1;
            sum1 += nums[i - 1];
            sum2 -= nums[i];
        }     

        return sum1 == sum2 ? nums.size() - 1 : -1;
    }
};
