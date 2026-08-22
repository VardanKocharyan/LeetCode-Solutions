class Solution {
public:
    bool checkDivisibility(int n) {
        int sum{}, total{1};
        int num{n};
        
        while (num) {
            sum += num % 10;
            total *= num % 10;
            
            num /= 10;
        }
        
        return (n % (sum + total) == 0);
    }
};
