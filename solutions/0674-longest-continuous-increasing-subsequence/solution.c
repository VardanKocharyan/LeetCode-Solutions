int findLengthOfLCIS(int* nums, int numsSize) {
    int sum = 1;
    int res  = 0;

    if (numsSize == 1) {
        return sum;
    }

    for(int i = 0 ; i < numsSize - 1 ; i++) {
        if (nums[i] < nums[i + 1]) {
            sum++;
        }
        else {
            sum = 1;
        }

        if(res < sum)
        {
            res = sum;
        }
    }
    return res;
}
