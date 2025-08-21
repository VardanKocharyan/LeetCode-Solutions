int myAtoi(char* str) {
        long long num = 0;
        int s = 1;
              
         while(*str == ' ' && *str != '\0') {
            ++str;
        }
        
        if (*str == '-') {
            s = -1;
            ++str;
        }
        else if (*str == '+') {
            ++str;
        }

        while(*str != '\0' && *str >= '0' && *str <= '9') {

            num = num * 10 + (*str - '0');

            if (s*num >  INT_MAX) return INT_MAX;
            if (s*num < INT_MIN) return INT_MIN;
            ++str;
        }
        return s*num;

}
