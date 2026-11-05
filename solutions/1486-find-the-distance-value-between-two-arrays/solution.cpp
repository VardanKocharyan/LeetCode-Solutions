class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans{};
        for (const int x : arr1) {
            for (const int y : arr2) {
                if (std::abs(x - y) <= d) goto next;
            }
            ++ans;
next:
        }
        return ans;
    }
};
