class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mission{};
        for (int i{}; i < nums.size(); ++i) {
            mission = mission ^ nums[i];
        }
        return mission;
    }
};
