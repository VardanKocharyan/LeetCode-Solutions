class Solution {
public:
    void dfs(int u, std::vector<int>& tmp, std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& res) {
        tmp.push_back(u);
        if (u == graph.size() - 1) {
            res.push_back(tmp);
            tmp.pop_back();
            return;
        };

        for (int nb : graph[u]) {
            dfs(nb, tmp, graph, res);    
        }

        tmp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        std::vector<std::vector<int>> res;
        std::vector<int> tmp;
        dfs(0, tmp, graph, res);
        return res;
    }
};
