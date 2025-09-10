int rangeBitwiseAnd(int left, int right) {
    int res1 = left;

  if((left ^ right) > left) return 0;

    while((left < right) && res1) {
        res1 &= (++left);
        res1 &= right;
        --right;

    }

    return res1;
}
