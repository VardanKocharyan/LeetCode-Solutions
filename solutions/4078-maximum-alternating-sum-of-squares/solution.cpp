class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        std::sort(
            nums.begin(),
            nums.end(),
            [](const int a, const int b) {return std::abs(a) < std::abs(b);}
        );

        long long ans{0};
        int l{}, r = nums.size() - 1;
        while (l < r) {
            ans += nums[r] * nums[r] - nums[l] * nums[l];
            ++l;
            --r;
        }

        if (l == r) ans += nums[l] * nums[l];

        return ans;
    }
};
