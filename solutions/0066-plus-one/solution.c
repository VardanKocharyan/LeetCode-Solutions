/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int carry = 1;
    for( int i = digitsSize - 1 ; i >= 0 ; --i){
        if(carry &&  digits[i] == 9){
            digits[i] = 0;
        }
        else{
            digits[i]++;
            --carry;
            break;
        }
    }

    *returnSize = (carry) ? digitsSize + 1 : digitsSize;
       
    int *res = (int*)malloc(sizeof(int) * (*returnSize));
    int i = *returnSize - 1;
    res[0] = carry;
    for(int i = 0 ; i < digitsSize ; ++i){
        res[*returnSize - i - 1] = digits[digitsSize - i - 1];
    }
    return res;
}

