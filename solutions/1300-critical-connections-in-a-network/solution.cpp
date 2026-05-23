class Solution {
public:
    void dfs(int u, int p, int& time, std::vector<int>& low, std::vector<int>& desc, 
            std::vector<std::vector<int>>& adj,  
            std::vector<std::vector<int>>& res) {
        low[u] = desc[u] = time++;
        for (int nb : adj[u]) {
            if (desc[nb] == -1) {
                dfs(nb, u, time, low, desc, adj, res);
                low[u] = std::min(low[u], low[nb]);
                if (desc[u] < low[nb]) {
                    res.push_back({u, nb});
                }
            } else if (nb != p) {
                low[u] = std::min(low[u], desc[nb]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        std::vector<std::vector<int>> adj(n);
        for (const std::vector<int>& v : connections) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        std::vector<std::vector<int>> res;
        std::vector<int> low(n, -1);
        std::vector<int> desc(n, -1);
        int time{};

        dfs(0, -1, time, low, desc, adj, res);

        return res;
    }
};
