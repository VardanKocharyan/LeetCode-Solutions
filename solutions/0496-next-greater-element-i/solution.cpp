class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> u_map;
        std::vector<int> ans(nums1.size(), -1);
        std::stack<int> st;

        for (int i{}; i < nums1.size(); ++i) u_map[nums1[i]] = i;

        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!st.empty() && st.top() < nums2[i]) st.pop();

            if (u_map.contains(nums2[i]) && !st.empty()) ans[u_map[nums2[i]]] = st.top();
            st.push(nums2[i]); 
        } 

        return ans;
    }
};
