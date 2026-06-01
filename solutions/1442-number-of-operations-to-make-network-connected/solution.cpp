class Solution {
public:
    struct DSU {
        std::vector<int> p;

        DSU(int n) {
            p.assign(n, -1);
        }

        int find(int x) {
            if (p[x] < 0) return x;
            return p[x] = find(p[x]);
        }

        bool unite(int x, int y) {
            int a = find(x);
            int b = find(y);

            if (a == b) return false;

            if (p[a] <= p[b]) {
                p[a] += p[b];
                p[b] = a;
            } else {
                p[b] += p[a];
                p[a] = b;                
            }
            return true;
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU d(n);
        int cycle{}, comp{};

        for (const std::vector<int>& e : connections) {
            if (!d.unite(e[0], e[1]) ) ++cycle;
        }

        for (int nb : d.p) {
            if (nb >= 0) continue;
            ++comp;
        }

        if (comp != 1 && comp - 1 > cycle) return -1;

        return comp - 1;
    }
};
