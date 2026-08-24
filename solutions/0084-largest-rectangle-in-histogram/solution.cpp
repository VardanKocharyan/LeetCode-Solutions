class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int, int>> st;
        int max_area{};

        for (int i{}; i < heights.size(); ++i) {
            int start = i;
            while (!st.empty() && st.top().first > heights[i]) {
                auto [value, idx] = st.top();
                st.pop();

                max_area = std::max<int>(max_area, value * (i - idx) );

                start = idx;
            }
            st.push({heights[i], start});
        }

        while (!st.empty()) {
            auto [value, idx] = st.top();
            st.pop();

            max_area = std::max<int>(max_area, value * (heights.size() - idx) );
        }
        
        return max_area;
    }
};
