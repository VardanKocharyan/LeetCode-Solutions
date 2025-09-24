bool isPalindrome(char* s) {
    int j = 0;
    int i = 0;
    
    while(s[j] != '\0') ++j;
    --j;

    while(i < j) {
        if(!((s[i] >= '0' && s[i] <= '9') || 
        (s[i] >= 'A' && s[i] <= 'Z') || 
        (s[i] >= 'a' && s[i] <= 'z'))) {
            ++i;  
            continue;
        }
        else if(!((s[j] >= '0' && s[j] <= '9') || 
        (s[j] >= 'A' && s[j] <= 'Z') || 
        (s[j] >= 'a' && s[j] <= 'z'))) { 
            --j;   
            continue;
        }
        else {
            if ((s[i] | 32) != (s[j] | 32 )) return false;
            ++i;
            --j;
        }
    }
    return true;
}
