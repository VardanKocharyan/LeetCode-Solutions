class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, size_t> u;
        for(size_t i{}; i< nums.size(); ++i)
        {
            if(++u[nums[i]] > 1) return true;
        }
        return false;
    }
};
