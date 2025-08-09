int addDigits(int num) {
    int sum = 0;
    while(num / 10){
        while(num){
            sum = sum + (num % 10);
            num /= 10;
        }
        num = sum;
        sum = 0;
    }
    return num;
}
