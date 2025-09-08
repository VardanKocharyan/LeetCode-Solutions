int hammingWeight(int n) {
    long count = 0;
    int i = 0;
    while(n) {
        if (n & 1) {
            ++count;
        }
            n >>= 1; 
            
    }
    return count;
}
