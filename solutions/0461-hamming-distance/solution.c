int hammingDistance(int x, int y) {
     unsigned long long count = 0;
    unsigned long long change = 1;
    while (x ^ y) {
        if((y & change) != (x & change)){
            x ^= change;
            ++count;
        }
        change = change << 1;
    }
    return count;
}
