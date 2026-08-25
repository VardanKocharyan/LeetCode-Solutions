class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<int, int> mp;
        int first{}, last = std::numeric_limits<int>::max();

        for (const char ch : t) --mp[ch];

        int start{};

        int count{};
        for (int end{}; end < s.length(); ++end) {
            
            if (start != end && s[start] == s[end] && mp[s[start]] >= 0 ) {
                
                while ( !mp.contains(s[++start]) ) {}

            } else if ( mp.contains(s[end]) ) {
                
                if (mp[s[end]]++ < 0) ++count;
            
            }

            while (!mp.contains(s[start]) && start <= end ) ++start;

            while ( (mp.contains(s[end]) && mp[s[end]] >= 0) && count == t.length() ) {
                if ( (last - first) > (end - start) ) {
                    last = end;
                    first = start;
                }

                if (--mp[s[start++]] < 0) --count;

                while (!mp.contains(s[start]) && start < end ) ++start;
            }
        }

        return last == std::numeric_limits<int>::max() ? "" : std::string(s.begin() + first, s.begin() + last + 1);
    }
};
