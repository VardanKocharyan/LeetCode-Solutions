class Solution {
public:
    int maxArea(vector<int>& height) {
        int begin{}, end = height.size() - 1;
        int ans{};

        while (begin < end) {
            if (height[begin] >= height[end]) {
                ans = std::max(ans, (end - begin) * height[end]);
                --end;
            } else {
                ans = std::max(ans, (end - begin) * height[begin]);
                ++begin;
            }
        } 

        return ans;
    }
};
