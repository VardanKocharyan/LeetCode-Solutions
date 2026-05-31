class Solution {
public:
    struct DSU {
        std::vector<char> parent;
        std::vector<int> rank;

        DSU(int n = 26) {
            parent.resize(n);
            rank.assign(n, 0);
            for (int i{}; i < n; ++i) {
                parent[i] = i + 'a';
            }
        }

        char find(char x) {
            if (parent[x - 'a'] == x) return x;
            return parent[x - 'a'] = find(parent[x - 'a']);
        }

        bool unite(char x, char y) {
            char a = find(x);
            char b = find(y);

            if (a == b) return false;

            if (rank[a - 'a'] > rank[b - 'a']) parent[b - 'a'] = a;
            else if (rank[b - 'a'] > rank[a - 'a']) parent[a - 'a'] = b;
            else {
                parent[b - 'a'] = a;
                ++rank[a - 'a'];
            }
            return true;
        }
    };

    bool equationsPossible(vector<string>& equations) {
        DSU d;

        for (auto& s : equations) {
            if (s[1] == s[2]) {
                d.unite(s[0], s[3]);
            }
        }

        for (auto& s : equations) {
            if (s[1] == '!' && d.find(s[0]) == d.find(s[3])) return false;
        }
        return true;
    }
};
