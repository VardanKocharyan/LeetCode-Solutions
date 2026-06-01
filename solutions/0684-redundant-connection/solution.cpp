class Solution {
public:
    struct DSU {
        std::vector<int> parent;
        std::vector<int> rank;

        DSU(int n) {
            parent.resize(n + 1);
            rank.assign(n + 1, 0);
            for (int i{}; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        bool unite(int x, int y) {
            int a = find(x);
            int b = find(y);

            if (a == b) return false;

            if (rank[a] > rank[b]) parent[b] = a;
            else if (rank[b] > rank[a]) parent[a] = b;
            else {
                parent[b] = a;
                ++rank[a];
            }
            return true;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU d(n);

        for (auto& v : edges) {
            if ( !d.unite(v[0], v[1]) ) return v;
        }
        return {};
    }
};
