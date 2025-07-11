int barev(char c){
    switch(c){
        case 'I': 
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default: return 0; 
    }
}

int romanToInt(char* s) {
    int a = 0;
    int b = 0;
    int sum = 0;

    for(int i = 0 ; i < strlen(s); i++){
        a = barev(s[i]);
        b = barev(s[i + 1]);
        
        if( a < b ){
            sum += - (a - b);
            ++i;
            printf("if");
        }
        else{
            sum += a; 
            printf("else");
        }
        printf("%d \n" , sum);
    }
    return sum ;
}
