int strStr(char* haystack, char* needle) {
    if (*needle == '\0') return 0;

    for(int i = 0; haystack[i] != '\0' ; ++i) {
        int idx = 0;
        while(needle[idx] != '\0' && haystack[idx + i] == needle[idx]) {
            ++idx;
        }
        if (needle[idx] == '\0') {
            return i;
        }
    }
    return -1;
}
