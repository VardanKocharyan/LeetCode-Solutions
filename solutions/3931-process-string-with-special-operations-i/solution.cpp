class Solution {
public:
    // void Reverse(std::string& res) {
    //     int l{}, r = res.length() - 1;
    //     while (l < r) 
    //         std::swap(res[l++], res[r--]);
    // }

    string processStr(string s) {
        std::string res;
        
        for (const char ch : s) {
            if (ch == '*') {
                if (!res.empty()) res.pop_back();
            } else if (ch == '#') {
                if (!res.empty()) res += res;
            } else if (ch == '%') {
                if (res.length() > 1) std::reverse(res.begin(), res.end());
            } else {
                res.push_back(ch);
            }
        }

        return res;
    }
};
