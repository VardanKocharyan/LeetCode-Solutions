class Solution {
public:
    int maximumLengthSubstring(string s) {
        std::vector<int> visited(26, 0);
        int max{};
        int curry{};
        int j{};

        for (const char ch : s) {
            if (visited[ch - 'a'] == 2) {
                for (; visited[ch - 'a'] == 2; ++j) {
                    --visited[s[j] - 'a'];
                    --curry;
                }
            }
                ++curry;
                ++visited[ch - 'a'];
            
            max = std::max(max, curry);
            std::cout << "CURRY: " << curry << " MAX: " << max << " " << ch << '\n';
        }

        return max;
    }
};

// for(right -> n) {
//     include window

//     while(violation) {

//     }

//     res update
// }
