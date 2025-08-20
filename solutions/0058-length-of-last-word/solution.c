int lengthOfLastWord(char* s) {
    int count = 0;
    int len = 0;
    while(*s)
    {
        s++;
        len++;
    }
    s--;
    len--;
    while(len > 0 && *s == ' ')
    {
        s--;
        len--;
    }
    while(len >= 0 && *s != ' ' && *s )
    {
        count++;
        s--;
        len--;
    }
    return count;
}
