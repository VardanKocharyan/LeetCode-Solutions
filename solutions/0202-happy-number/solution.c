bool isHappy(int n) {
    if((n < 10 && n != 7) && n != 1) return false;
    int sum = 0;

    while(n != 1) {
        while(n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        if(sum != 1 && sum != 7 && sum < 10) return false;
        n = sum;
        sum = 0;
    }
    return true;

}
