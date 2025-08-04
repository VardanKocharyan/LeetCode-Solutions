int minBitFlips(int start, int goal) {
    unsigned long long count = 0;
    unsigned long long change = 1;
    while (start ^ goal) {
        if((goal & change) != (start & change)){
            start = start ^ change;
            ++count;
        }
        change = change << 1;
    }
    return count;
}
