class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int p1{}, p2{}, p3{};
        for (int i{};i<n;++i) {
            int curr=costs[i]+std::min({1+p1,4+p2,9+p3});
            p3=p2;
            p2=p1;
            p1=curr;
        }
        return p1;
    }
};
