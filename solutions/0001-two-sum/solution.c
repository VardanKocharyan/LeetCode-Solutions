/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ptr = malloc(2*sizeof(int));
    int i = 0;
    int j = numsSize - 1;

    if (numsSize == 2){
        ptr[0] = 0;
        ptr[1] = 1;
        return ptr;
    }

    for(int i = 0 ; i < numsSize ; ++i){
        for(int j = i + 1 ; j < numsSize ; ++j){
                if(target == nums[i] + nums[j]){
                    ptr[0] = i;
                    ptr[1] = j;
                    *returnSize = 2;

                    return ptr; 
                }
        }
    }
return NULL;
    
}
