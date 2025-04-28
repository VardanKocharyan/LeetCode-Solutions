int missingNumber(int* nums, int numsSize){
    int mission = 0;
    for(int i = 0 ; i < numsSize ; i++){
        mission = nums[i] ^ (i+1) ^ mission;
    }
    return mission;
}
