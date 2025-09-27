bool isSubsequence(char* s, char* t) {
    while(*t != '\0' && *s != '\0') {
        if(*t == *s) {
            ++s;
            ++t;
        }
        else {
            ++t;
        }

    }
    return *s == '\0';  
}
