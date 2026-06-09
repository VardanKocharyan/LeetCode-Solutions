class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int l{-1};
        for(int r{}; r < nums.size(); ++r) {
            if(nums[r] <= pivot) {
                int k{r-1};
                int key = nums[r];
                while(k > l) {
                    nums[k+1] = nums[k];
                    --k;
                }
                if(key != pivot) {
                    while(k >= 0 && nums[k] == pivot) {
                        nums[k+1] = nums[k];
                        --k;
                    }
                }
                nums[k+1] = key;
                ++l;
            }
        }
        return nums;
    }
};       
