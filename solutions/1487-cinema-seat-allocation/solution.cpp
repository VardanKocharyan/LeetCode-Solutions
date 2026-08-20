class Solution {
public:
    int Valid(const std::vector<int>& v) {
        bool a{true}, b{true}, c{true};
        for (const int nb : v) {
            if (nb == 4 || nb == 5) {
                a &= false;
                b &= false;
            } else if(nb == 6 || nb == 7) {
                b &= false;
                c &= false;
            } else if (nb == 2 || nb == 3) {
                a &= false;
            } else if (nb == 8 || nb == 9) {
                c &= false;
            }

            if (!a && !b && !c) return 0;
        }

        if (a && c) return 2;
        return 1;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res{};
        std::unordered_map<int, std::vector<int>> cont;

        for (const std::vector<int>& v : reservedSeats) {
            int row = v[0];
            int seat = v[1];

            cont[row].push_back(v[1]);
        }

        for (const auto[key, value] : cont) {
            res += Valid(value);
        }

        return res + (n - cont.size()) * 2;
    }
};
