class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int count{};

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ++count;
            for (int nb : adj[u]) {
                if (--indeg[nb] == 0) {
                    q.push(nb);
                }
            }
        }
        return count == numCourses;
    }
};
