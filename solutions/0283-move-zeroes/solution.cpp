class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t j{};
        for(size_t i{}; i < nums.size(); ++i) 
        {
            if (nums[i]) 
            {
                nums[j] = nums[i];
                if (i != j) 
                {
                    nums[i] = 0;
                }
                ++j;
            }
        }
    }
};
