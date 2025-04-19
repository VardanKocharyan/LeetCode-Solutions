int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int sum = 0;
    int result = 0;
/*
    if(numsSize == 0)
    {
        return 0;
    }
    else if(numsSize == 1)
    {
        return result;
    }
*/
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
