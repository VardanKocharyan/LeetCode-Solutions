class Solution {
public:
    void dfs(int i, int target, std::vector<int>& tmp, std::vector<int>& nums, std::vector<std::vector<int>>& res) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }

        for ( ; i < nums.size(); ++i) {
            if (target >= nums[i]) {
                tmp.push_back(nums[i]);
                dfs(i, target - nums[i], tmp, nums, res);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> tmp;
        dfs(0, target, tmp, candidates, res);

        return res;
    }
};
