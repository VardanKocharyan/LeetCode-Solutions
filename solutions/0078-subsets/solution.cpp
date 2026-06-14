class Solution {
public:
    void dfs(int i, std::vector<int>& tmp, std::vector<int>& nums, std::vector<std::vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(tmp);
            return;
        }

        tmp.push_back(nums[i]);
        dfs(i + 1, tmp, nums, res);
        tmp.pop_back();
        dfs(i + 1, tmp, nums, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> tmp;
        dfs(0, tmp, nums, res);

        return res;
    }
};
