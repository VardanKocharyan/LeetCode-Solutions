class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        std::vector<int> start(flowers.size()), end(flowers.size());
        std::vector<int> res;

        for (int i{}; i < flowers.size(); ++i) {
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }

        std::sort(start.begin(), start.end());
        std::sort(end.begin(), end.end());

        for (const int p  : people) {
            int s = std::upper_bound(start.begin(), start.end(), p) - start.begin();
            int e = std::lower_bound(end.begin(), end.end(), p) - end.begin();
            
            res.push_back(s - e);
        }

        return res;
    }
};
