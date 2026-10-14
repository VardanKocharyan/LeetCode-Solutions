class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) {
            return "";
        }
        std::string ans;
        ans.insert(0, sum / 9, '9');
        if (sum % 9) ans.push_back(static_cast<char>(sum % 9 + '0'));
        num -= sum / 9 + (sum % 9 != 0);
        ans.insert(ans.length(), num, '0');
        return ans;
    }
};
