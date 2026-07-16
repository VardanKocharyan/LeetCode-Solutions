class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [] (const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });    

        std::vector<std::vector<int>> res;
        std::vector<int> curr(intervals[0]);

        for (int i{1}; i < intervals.size(); ++i) {
            bool update = false;

            if (curr[1] >= intervals[i][0]) {
                update = true;
                curr[0] = std::min(intervals[i][0], curr[0]);
                curr[1] = std::max(intervals[i][1], curr[1]);
            }

            if (!update) {
                res.push_back(curr);
                curr = intervals[i];
            }
        }

        res.push_back(curr);

        return res;
    }
};
