class Solution {
public:
    int roman(char c) {
        switch(c) {
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
        }
        return 0;
    }
    int romanToInt(string s) {
        int sum{};
        
        for (int prev{}; prev < s.length(); ++prev) {
            int first = roman(s[prev]);
            int second = roman(s[prev + 1]);

            if (first < second) {
                sum += second - first;
                ++prev;
            } else {
                sum += first;
            }
        }
        return sum;    
    }
};
