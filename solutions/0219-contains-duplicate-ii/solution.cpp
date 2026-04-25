class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;
        for (int i{}; i < nums.size(); ++i) {
            if (mp.contains(nums[i])) {
                if (i - mp[nums[i]] <= k) return true;
                else {
                    mp[nums[i]] = i;
                }
            } else {
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};
