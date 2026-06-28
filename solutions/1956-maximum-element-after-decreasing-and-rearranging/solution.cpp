class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int res{1};
        std::sort(arr.begin(), arr.end());

        for (int i{1}; i < arr.size(); ++i) 
            if (arr[i] > res) ++res;
        
        return res;
    }
};
