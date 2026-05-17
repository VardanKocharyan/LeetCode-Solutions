class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if (edges[0][1] == edges[1][1] || edges[0][0] == edges[1][1]) return edges[1][1];
        return edges[1][0];    
    }
};
