bool isPowerOfThree(int n) {
    long res=1;
    while(n > res){
        res = res * 3;
    }
    return (n == res);
}
