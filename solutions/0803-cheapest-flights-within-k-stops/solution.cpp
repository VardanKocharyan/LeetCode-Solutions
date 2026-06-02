class Solution {
public:
    void makeAdj(std::vector<std::vector<int>>& f, std::vector<std::vector<std::pair<int, int>>>& adj) {
        for (const std::vector<int>& v : f) {
            int from = v[0];
            int to = v[1];
            int w = v[2];
            adj[from].push_back({to, w});
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        std::queue<std::pair<int, int>> q;
        std::vector<int> dist(n, std::numeric_limits<int>::max());

        makeAdj(flights, adj);        

        q.push({src, 0});
        dist[src] = 0;

        while (!q.empty() && (k--) >= 0) {
            int s = q.size();

            while (s--) {
                auto [u, distantion] = q.front();
                q.pop();

                if (u == dst){
                    continue;
                }
                for (const auto& [nb, w] : adj[u]) {
                    if (dist[nb] > distantion + w) {
                        dist[nb] = distantion + w;
                        q.push( {nb, dist[nb]} );
                    }                  
                }
            }
        }

        return dist[dst] == std::numeric_limits<int>::max() ? -1 : dist[dst];
    }
};

