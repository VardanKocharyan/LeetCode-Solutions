class Solution {
public:
    bool dfs(int u, std::vector<int>& Color, std::vector<std::vector<int>>& adj) {
        Color[u] = 1;

        for (int nb : adj[u]) {
            if (Color[nb] == 1) return false;
            if (!Color[nb] && !dfs(nb, Color, adj)) return false;
        }
        Color[u] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        std::vector<int> res;
        std::vector<int> Color(n);

        for (int i{}; i < n; ++i) {
            if (Color[i] == 0) dfs(i, Color, graph);
            if (Color[i] == 2) res.push_back(i);     
        }

        return res;
    }
};
