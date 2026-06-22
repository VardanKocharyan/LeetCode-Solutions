class Solution {
public:
    int maxNumberOfBalloons(string text) {
        std::array<int, 5> arr;
        for (const char ch : text) {
            switch (ch) {
                case 'b': ++arr[0]; break;
                case 'a': ++arr[1]; break;
                case 'l': ++arr[2]; break;
                case 'o': ++arr[3]; break;
                case 'n': ++arr[4]; break;
                default: continue;
            }
        }

        return std::min({arr[0], arr[1], arr[2] / 2, arr[3] / 2, arr[4]});
    }
};
