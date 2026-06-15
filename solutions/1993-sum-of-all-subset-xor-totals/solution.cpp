class Solution {
private:
    int sum{};
public:
    void dfs(int i, int res, std::vector<int>& nums) {
        if (i == nums.size()) {
            sum += res;
            return;
        }

        sum += res;

        for ( ; i < nums.size(); ++i) {
            dfs(i + 1, res ^ nums[i], nums);
        }
    }

    int subsetXORSum(vector<int>& nums) {
        int res{};
        dfs(0, res, nums);
        return sum;
    }
};
