int mySqrt(int x){
    if(x == 0) return x;
    if(x < 2) return 1;
    
    int y = 2;
    while(y <= x/2){
        if((long)y * y > x){
            break;
        }
        ++y;
    }

    return y - 1;
}
