int maximumProduct(int* nums, int numsSize) {
    int a = INT_MIN;
    int b = INT_MIN;
    int c = INT_MIN;
    int d = INT_MAX;
    int e = INT_MAX;

    for(int i = 0; i < numsSize; ++i) {
        if (a < nums[i]) {
            c = b;
            b = a;
            a = nums[i];
        }
        else if (b < nums[i]) {
            c = b;
            b = nums[i];
        }
        else if (c < nums[i]) c = nums[i];

        if (d > nums[i]) {
            e = d;
            d = nums[i];
        }
        else if (e > nums[i]) e = nums[i];
    }

    d *= e * a;
    a *= b * c;

    return (a > d) ? a : d; 
}
