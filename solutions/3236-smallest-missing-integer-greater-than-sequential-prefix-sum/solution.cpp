class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int i{1}, sum = nums[0];
        for (; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] + 1) break;
            sum += nums[i];
        }

        std::unordered_set<int> s(nums.begin(), nums.end());

        while (s.contains(sum)) ++sum;

        return sum;
    }
};
