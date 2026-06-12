class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        base %= MOD;

        while (exp > 0) {
            if (exp & 1)
                res = (res * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return res;
    }
    
    void makeAdj(std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& adj) {
        for (const std::vector<int>& e : edges) {
            int from = e[0] - 1;
            int to   = e[1] - 1;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
    }

    int getHeight(int u, int p, std::vector<std::vector<int>>& adj) {
        int max{};
        for (int nb : adj[u]) {
            if(nb != p)
                max = std::max(max, getHeight(nb, u, adj));
        }

        return 1 + max;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        std::vector<std::vector<int>> adj(n);
        makeAdj(edges, adj);

        int height = getHeight(0, -1, adj);

        return modPow(2, height-2);
    }
};
