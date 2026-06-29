class Solution {
public:
    bool check(const std::string& s, const std::string& w) {
        int n = w.length();
        int m = s.length();
        for (int i{}; i + m <= n; ++i) {
            bool f = true;
            for (int j{}; j < m; ++j) {
                if (w[i + j] != s[j]) {
                    f = false;
                    break;
                }
            }
            if (f) return true;
        }
        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int count{};
        for (const std::string& s : patterns) {
            if (check(s, word)) ++count;
        }
        return count;
    }
};
