class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count{1};
        int val = nums[0];
        int n = nums.size();


        for (int i{1}; i < n; ++i) {
            if (val == nums[i]) ++count;
            else {
                if (!(--count)) {
                    val = nums[++i];
                    count = 1;
                }
            }
        }
        return val; 
    }
};
