class Solution {
public:
    void makeAdj(std::vector<std::vector<int>>& edges, std::vector<std::vector<std::pair<int, int>>>& adj) {
        for (const std::vector<int>& e : edges) {
            int from = e[0];
            int to = e[1];
            int w = e[2];
            adj[from].push_back({to, w});
            adj[to].push_back({from, w});
        }
    }

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        using tiii = std::tuple<int, int, int>;
        using pii = std::pair<int, int>;

        int n = passingFees.size();
        int dst = n - 1;
        std::vector<std::vector<pii>> adj(passingFees.size());
        std::vector<int> dist(n, std::numeric_limits<int>::max());
        std::priority_queue<tiii,
                            std::vector<tiii>,
                            std::greater<tiii> > pq;

        makeAdj(edges, adj);

        pq.push({passingFees[0], 0, 0});
        dist[0] = 0;
        int min = std::numeric_limits<int>::max();
        while (!pq.empty()) {
            auto [cost, u, d] = pq.top();
            pq.pop();
            for (auto [nb, w] : adj[u]) {
                if (dist[nb] > d + w) {
                    dist[nb] = d + w;
                    
                    if (d + w <= maxTime) {
                        if (nb == dst) {
                            min = std::min(min, cost + passingFees[nb]);
                            continue;
                        }
                        pq.push({cost + passingFees[nb], nb, d + w});
                    }
                }
            }
        }

        return min == std::numeric_limits<int>::max() ? -1 : min;
    }
};
