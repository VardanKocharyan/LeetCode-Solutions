/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* ptr = (int*) malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    long product = 1;
    int count = 0;
    int idx = 0;

    for(int i = 0; i < numsSize; ++i) {
        if (nums[i]) {
            product *= nums[i];
        }
        else {
            ++count;
            idx = i;
        }
        ptr[i] = 0;
    }
    
    if(count > 1) return ptr;
    if(count == 1) {
        ptr[idx] = product;
        return ptr;
    }

    for(int i = 0; i < numsSize; ++i) {
        ptr[i] = product / nums[i];
    }
    return ptr;
}
