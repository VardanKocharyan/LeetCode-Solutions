class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;
        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>
        > pq;

        for (const int nb : nums) {
            ++mp[nb];
        }

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            pq.push({it->second, it->first});
        }

        std::vector<int> ans;
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
