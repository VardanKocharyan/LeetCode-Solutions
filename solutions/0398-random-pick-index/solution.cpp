class Solution {
private:
    std::unordered_map<
            int, 
            std::vector<int>
        >mp;

public:
    Solution(vector<int>& nums) {
        for (int i{}; i < nums.size(); ++i) mp[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        const std::vector<int>& v = mp[target];
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(0, v.size() - 1);
        
        return v[distrib(gen)];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
