int maxSubArray(int* nums, int numsSize) {
    int sum = nums[0];
    int max = sum;

    for(int i = 1; i < numsSize; ++i) {

        if (max < sum) max = sum;
        if (sum < 0) sum = 0;
        sum += nums[i];
    }
    
    if(max < sum) max = sum;
    
    return max;
}
