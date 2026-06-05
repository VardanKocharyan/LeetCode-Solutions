class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l{1};
        int r = piles[0];
        
        for (int i{1}; i < piles.size(); ++i) {
            r = std::max(r, piles[i]);
        }

        int res = r;
        while (l <= r) {
            int m = l + (r - l) / 2;
            long time{};

            for (int nb : piles) 
                time += (nb + m - 1) / m;

            if (time <= h) {
                res = m;
                r = m - 1;
            }
            else l = m + 1;
        }

        return res;
    }
};
