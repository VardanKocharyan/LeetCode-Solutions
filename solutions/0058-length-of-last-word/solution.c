int lengthOfLastWord(char* s) {
    int count = 0;
    int len = 0;
    while(*s != '\0')
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
    while(len >= 0 && *s != ' ' && *s != '\0')
    {
        count++;
        s--;
        len--;
    }
    return count;
}
