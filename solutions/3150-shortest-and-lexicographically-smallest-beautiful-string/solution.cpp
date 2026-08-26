class Solution {
public:
    template <class InputIt>
    bool LS(InputIt f1, InputIt l1, InputIt f2, InputIt l2) {
        while (f1 <= l1) {
            if (*f1 == *f2) {
                ++f1;
                ++f2;
            } else if (*f1 == '1' && *f2 == '0') {
                return true;
            } else return false;
        }

        return false;
    }

    string shortestBeautifulSubstring(string s, int k) {
        int count{};
        int first{}, last = std::numeric_limits<int>::max();

        int start{};
        for (int end{}; end < s.length(); ++end) {
            if (s[end] == '1') ++count;

            if (count == k && start <= end) {
                while (s[start] != '1') ++start;

                if ( ((last - first) > (end - start)) || 
                    ((last - first) == (end - start) && LS(s.begin() + first, s.begin() + last, s.begin() + start, s.begin() + end)) ) {
                    last  = end;
                    first = start;
                }

                ++start;
                --count;
            }
        }

        return (last == std::numeric_limits<int>::max()) ? "" : std::string(s.begin() + first, s.begin() + last + 1);
    }
};
