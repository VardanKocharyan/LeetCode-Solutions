class Solution {
public:
    int SumOfDigits(int n) {
        int sum{};
        while(n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        for (int i{}; i < nums.size(); ++i) {
            if (SumOfDigits(nums[i]) == i) return i; 
        }
        return -1;
    }
};
