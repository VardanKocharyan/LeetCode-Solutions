class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        std::vector<int> finish{0,1};
        if (n == 2) return finish;

        std:unordered_map<int, int> mp;
        
        for (int i{}; i < n; ++i) {
            auto it = mp.find(target - nums[i]);
            if (it != mp.end()) {
                finish[0] = mp[target - nums[i]];
                finish[1] = i;
                break;
            }
            mp[nums[i]] = i;
        }
        return finish;
    }
};
