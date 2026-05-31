class Solution {
public:
    void makeAdj(std::vector<std::vector<int>>& times, std::vector<std::vector<std::pair<int, int>>>& adj) {
        for (const auto& edge : times) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            int w = edge[2];
            adj[u].push_back({v, w});
        }
    }

    void Djikstre(int src, std::vector<int>& dist, std::vector<std::vector<std::pair<int, int>>>& adj) {
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>> > pq;

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            auto [distance, u] = pq.top(); pq.pop();

            if (distance != dist[u]) continue;

            for (auto [nb, d] : adj[u]) {
                if (dist[u] + d < dist[nb]) {
                    dist[nb] = dist[u] + d;
                    pq.push({dist[nb], nb});
                } 
            }
        }
    }

    int test(std::vector<int>& dist) {
        int max = std::numeric_limits<int>::min();

        for (int d : dist) {
            if (d == std::numeric_limits<int>::max()) return -1;
            max = std::max(max, d);
        }
        return max;
    }


    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        std::vector<int> dist(n, std::numeric_limits<int>::max());
        makeAdj(times, adj);

        Djikstre(k - 1, dist, adj);

        return test(dist);
    }
};
