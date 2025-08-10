bool isPowerOfThree(int n) {
    long res=1;
    while(n >= res){
        if(n == res) return true;
        res = res * 3;
    }
    return false;

}
