void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;
        
    while(i >=0 && nums[i] >= nums[i + 1]){
        --i;
    }
    if(i >= 0){
        int j = numsSize - 1;
        while(nums[j] <= nums[i]){
            --j;
        }
            nums[i] ^= nums[j];
            nums[j] ^= nums[i];
            nums[i] ^= nums[j];
        
    }
    int idx1 = i + 1;
    int idx2 = numsSize - 1;
    while(idx1 < idx2){
        nums[idx1] ^= nums[idx2];
        nums[idx2] ^= nums[idx1];
        nums[idx1++] ^= nums[idx2--];
    }
}
