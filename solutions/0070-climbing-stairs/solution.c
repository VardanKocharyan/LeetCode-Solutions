int climbStairs(int n) {
    int a = 1;
    int b = 1;
    int c = 0;
    if (n == 1 || n == 2) return n;
    n--;
    while(n--) {
        c = a + b;
        a = b;
        b = c; 
    }
    return c;
}
