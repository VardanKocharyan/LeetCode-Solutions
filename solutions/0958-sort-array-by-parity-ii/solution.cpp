class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even{}, odd{1}, n = nums.size();

        while (odd < n && even < n) {

            while (even < n && (nums[even] % 2 == 0)) {
                even += 2;
            }

            while (odd < n && (nums[odd] % 2 == 1)) { 
                odd += 2;
            }

            if (even < n && odd < n) {
                std::swap(nums[even], nums[odd]);
                odd += 2;
                even += 2;
            }
        }
        return nums;
    }
};
