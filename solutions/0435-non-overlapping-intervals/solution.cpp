class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [] (const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int count{1};
        int idx{};

        for (int i{1}; i < intervals.size(); ++i) {
            if (intervals[idx][1] <= intervals[i][0]) {
                ++count;
                idx = i;
            }
        }

        return intervals.size() - count;
    }
};
