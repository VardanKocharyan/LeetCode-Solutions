bool isPalindrome(int x) {
    long long int z = 0;

    if(x < 0 || (x % 10 == 0 && x != 0)){
        return false;
    }

    while (x > z) {
        z = z * 10  +  x % 10;
        x = x / 10;
    }

    return (x == z || x == z/10);
}
