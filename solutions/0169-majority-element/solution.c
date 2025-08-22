int majorityElement(int* nums, int numsSize) {
    if(numsSize == 1) return nums[0];
    int idx1 = 0;
    int idx2 = 1;
    int count = 1;
    int s = (numsSize % 2) ? numsSize/2 + 1 : numsSize/2 ;
    
    while(idx1 < numsSize){
        if (idx2 == numsSize) {
            ++idx1;
            idx2 = idx1 + 1;
            count = 1;
        }

        if (nums[idx1] == nums[idx2]) {
                ++count;
                nums[idx2] ^= nums[numsSize - 1];
                nums[numsSize - 1] ^= nums[idx2];
                nums[idx2] ^= nums[numsSize - 1];
                --numsSize;
        }
        else {
            ++idx2;
        }

                if (count >= s) {
            count = nums[idx1];
            break;
        }
    }
    return count;
}
