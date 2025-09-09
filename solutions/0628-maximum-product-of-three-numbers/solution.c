int maximumProduct(int* nums, int numsSize) {
    int res1 = 1;
    int res2 = 1;
    for(int i = 0; i < 3; ++i) {
        for(int j = i + 1; j < numsSize; ++j) {
            if (nums[i] < nums[j] && nums[i] != nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        res1 *= nums[i]; 
    }
    res2 *= nums[0];
    for(int i = 0; i < 2; ++i) {
        for(int j = i + 1; j < numsSize; ++j) {
            if (nums[i] > nums[j] && nums[i] != nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        res2 *= nums[i]; 
    }
    return (res1 > res2) ? res1 : res2;
}
