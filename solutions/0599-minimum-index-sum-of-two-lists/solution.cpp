class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int min = std::numeric_limits<int>::max();
        int idx{};
        std::unordered_map<std::string, int> findLeast;

        for (int i{}; i < list1.size(); ++i) {
            findLeast[list1[i]] = i;
        }
        list1.clear();

        for (int i{}; i < list2.size(); ++i) {
            if (findLeast.contains(list2[i])) {
                int m = i + findLeast[list2[i]];
                if (min > m) {
                    list1.clear();
                    list1.push_back(list2[i]);
                    min = m;
                } else if (min == m) {
                    list1.push_back(list2[i]);
                }
            }
        }

        return list1;
    }
};
