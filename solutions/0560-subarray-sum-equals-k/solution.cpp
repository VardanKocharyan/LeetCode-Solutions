class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        std::unordered_map<int, int> mp;
        mp[0] = 1;
        int curr{};
        int total{};
        
        for (auto n : nums) {
            curr += n;
            if (mp.contains(curr - k)) total += mp[curr - k];
            ++mp[curr];
        }
        return total;
    }
};
