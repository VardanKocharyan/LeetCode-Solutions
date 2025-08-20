int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int sum = 0;
    int result = 0;

    for(int i = 0 ; i < numsSize ; i++)
    {
        if(nums[i] == 1)
        {
            sum++;
            if(sum > result)
            {
                result = sum;
            }
        }
        else 
        {
            sum = 0;
        }
    }
    
    return result;
}
