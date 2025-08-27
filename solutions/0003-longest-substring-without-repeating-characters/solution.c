int lengthOfLongestSubstring(char* s) {
    if (!*s) return 0;
    int count = 1;
    int max = 1;
    int idx1 = 0;
    int idx2 = 0;
    
    while(s[idx2] != '\0') {
        for(int i = idx1; i < idx2; ++i) {
            if (s[i] == s[idx2]) {
                idx1 = i + 1;
                break;
            }
            else {
                ++count;
            }
        }
        if (max < count) {
            max = count;
        }
        ++idx2;
        count = 1;
    }
    return max;
}
