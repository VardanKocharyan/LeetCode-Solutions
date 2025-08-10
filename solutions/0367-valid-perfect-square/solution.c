bool isPerfectSquare(int num) {
    int a = 0;
    while((long) a * a < num){
        ++a;
    }
    if((long)a * a == num){
        return true;
    }
    return false;
}
