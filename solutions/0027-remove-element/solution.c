int removeElement(int* nums, int numsSize, int val) {
    int count = 0;
    if(numsSize == 0) return 0;

    for(int i = 0; i < numsSize; i++){
        if (val != nums[i]) {
            nums[count++] = nums[i];
        }
    }
    return count;
}
