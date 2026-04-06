class Solution {
public:
    string addBinary(string a, string b) {
        std::string res = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry{};

        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            res = char((sum % 2) + '0') + res;
            carry = sum / 2;
        }

        if (carry) res = char((carry) + '0') + res;

        return res;
    }
};
