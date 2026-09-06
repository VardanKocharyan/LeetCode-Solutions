class Solution {
public:
    struct Pos {
        int val;
        int i;
        int j;

        Pos(int val_, int i_, int j_) : val(val_), i(i_), j(j_) {}
        ~Pos() = default;
    };

    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m; 
    }


    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        std::vector<int> variants({1, 0, -1, 0, 1});
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

        auto comp = [](const Pos& a, const Pos& b) { return a.val > b.val; };
        std::priority_queue<Pos, std::vector<Pos>, decltype(comp)> pq(comp);

        pq.push(Pos(0, 0, 0));

        while (!pq.empty()) {
            Pos p = pq.top();
            pq.pop();

            int effort = p.val;
            int r = p.i;
            int c = p.j;

            if (r == n - 1 && c == m - 1) return effort;

            if (visited[r][c]) continue;
            visited[r][c] = true;
            
            for (int i{}; i < 4; ++i) {
                int nr = r + variants[i];
                int nc = c + variants[i + 1];

                if (isValid(nr, nc, n, m) && !visited[nr][nc]) {
                    int nEffort = std::max(effort, std::abs(heights[r][c] - heights[nr][nc]));
                    pq.push(Pos(nEffort, nr, nc));
                }
            }
        }

        return 0;
    }
};
