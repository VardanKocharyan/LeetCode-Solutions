class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> indeg(numCourses);

        for (const std::vector<int>& v : prerequisites) {
            adj[v[1]].push_back(v[0]);
            ++indeg[v[0]];
        }

        std::queue<int> q;

        for (int i{}; i < numCourses; ++i) {
            if (!indeg[i]) q.push(i); 
        }

        std::vector<int> res;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            res.push_back(u);
            for (int nb : adj[u]) {
                if (--indeg[nb] == 0) {
                    q.push(nb);
                }
            }
        }
        return (res.size() == numCourses) ? res : std::vector<int>{};
    }
};
