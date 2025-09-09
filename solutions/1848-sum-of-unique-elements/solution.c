int sumOfUnique(int* nums, int numsSize) {
    int *p = calloc(100, sizeof(int));
    int sum = 0;

    for(int i = 0; i < numsSize; ++i) {
        ++p[nums[i] - 1];
    }

    for(int i = 0; i < numsSize; ++i) {
        if (p[nums[i] - 1] == 1) sum += nums[i];
    }
    free(p);
    return sum;
}
