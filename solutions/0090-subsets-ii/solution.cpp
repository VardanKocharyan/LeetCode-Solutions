class Solution {
private:
    std::vector<std::vector<int>> res;

public:
    bool isVisited(int target, int visited) {
        return (visited & (1 << (target + 10)));
    }
    void dfs(int i, std::vector<int>& tmp, std::vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back(tmp);
            return;
        }

        res.push_back(tmp);

        int visited{};
        for ( ; i < nums.size(); ++i) {
            if (isVisited(nums[i], visited)) continue;

            tmp.push_back(nums[i]);
            visited |= (1 << (nums[i] + 10));
            dfs(i + 1, tmp, nums);
            tmp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<int> tmp;
        std::sort(nums.begin(), nums.end());
        dfs(0, tmp, nums);

        return res;
    }
};
