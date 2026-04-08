class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int> res{1, 2};
        int n = numbers.size() - 1;
        int first = 0;
        
        if (n + 1 == 2) return res;

        while(first < n && numbers[first] + numbers[n] != target) {
            if (numbers[first] + numbers[n] > target) {
                --n;
            } else {
                ++first;
            }
        }
        res[0] = first + 1;
        res[1] = n + 1;

        return res;
    }
};
