class Solution {
private:
    std::vector<std::vector<int>> res;
    
public:
    void dfs(int i, std::vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int j{i} ; j < nums.size(); ++j) {
            std::swap(nums[i], nums[j]);
            dfs(i + 1, nums);
            std::swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        dfs(0, nums);

        return res;
    }
};
