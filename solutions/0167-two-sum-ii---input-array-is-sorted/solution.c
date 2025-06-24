/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int index1 = 0;
    int index2 = numbersSize - 1;

    int* res = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
        while(1)
        {
            if(numbers[index1] + numbers[index2] == target){

                res[0] = index1 + 1;
                res[1] = index2 + 1;
                return res;
            }
            else if(numbers[index1] + numbers[index2] > target){
                --index2;
            }
            else{
                ++index1;
            }

            if(index1 == index2){        
                ++index1;
                index2 = numbersSize - 1;
            }
        }
    

    return returnSize;
}
