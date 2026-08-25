class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        std::vector<bool> visited(101, false);
        for (const int nb : nums) if (nb % k == 0) visited[nb] = true;

        int i{k};
        while (visited[i] && i + k < 101) i += k;

        return visited[i] ? i + k : i;
    }
};
