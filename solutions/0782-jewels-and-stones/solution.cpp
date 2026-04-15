class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        std::unordered_map<char, bool> priceless;
        int count{};

        for (int i{}; i < jewels.length(); ++i) {
            priceless[jewels[i]] = true;
        }

        for (int i{}; i < stones.length(); ++i) {
            if (priceless.contains(stones[i])) ++count;
        }
        return count;
    }
};
