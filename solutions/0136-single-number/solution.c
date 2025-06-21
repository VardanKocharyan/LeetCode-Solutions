int singleNumber(int* nums, int numsSize) 
{
    int mission = 0;
    for(int i = 0 ; i < numsSize ; i++)
        {
            mission = mission ^ nums[i];
        }
        return mission;
}
