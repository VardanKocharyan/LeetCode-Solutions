class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        
        std::vector<std::vector<int>> adj(n);

        for (const std::vector<int> v: edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        std::vector<bool> visited(n, false);
        std::queue<int> q;
        
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int nb : adj[curr]) {
                if (nb == destination) return true;
                if (!visited[nb]) {
                    q.push(nb);
                    visited[nb] = true;
                } 
            }
        }
        return false;
    }
};
