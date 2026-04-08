class Solution {
public:
    int greatest_divisor(int num1, int num2) {
        int divisor = num1;
        while (divisor > 1) {
            if (!(num1 % divisor) && !(num2 % divisor)) break;
            --divisor;
        }
        return divisor;
    }

    int findGCD(vector<int>& nums) {
        
        int min = nums[0];
        int max = nums[0];

        for (size_t i{}; i < nums.size(); ++i) {
            if (min > nums[i]) min = nums[i];
            if (max < nums[i]) max = nums[i];
        }

        return greatest_divisor(min, max);
    }
};
