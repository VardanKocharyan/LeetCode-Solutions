class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k{1};
        for (int next{1}, prev{0}; next < nums.size(); ++next) {
            if (nums[prev] != nums[next]) {
                nums[++prev] = nums[next];
                ++k;
            }
        }
        return k;
    }
};
