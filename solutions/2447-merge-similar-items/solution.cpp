class Solution {
public:

    int partition(std::vector<int>& vec, int l, int r) {
        if (l >= r) return l;
        int median = l + std::rand() % (r - l + 1);

        std::swap(vec[median], vec[r]);
    
        int i = l - 1;

        for (int j = l; j <= r; ++j) {
            if (vec[j] <= vec[r]) {
                std::swap(vec[j], vec[++i]);
            }
        }
        return i;
    }

    void quick_sort(std::vector<int>& vec, int l, int r) {
        if (l < r) {
            int p = partition(vec, l, r);

            quick_sort(vec, l, p - 1);
            quick_sort(vec, p + 1, r);
        }
    }

    void sort(std::vector<int>& vec) {
        int l{}, r = vec.size() - 1;
        quick_sort(vec, l, r);
    }

    void AddOnMap(std::unordered_map<int, std::vector<int>>& mp, vector<vector<int>>& vec, std::vector<int>& out) {
        for (int i{}; i < vec.size(); ++i) {
            int value = vec[i][0];
            int weight = vec[i][1];
            if (!mp.contains(value)) {
                mp[value] = vec[i];
                out.push_back(value);
            } else {
                mp[value][1]+= weight; 
            }
        }
    }
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        
        std::unordered_map<int, std::vector<int>> mp;
        std::vector<int> res;

        AddOnMap(mp, items1, res);
        AddOnMap(mp, items2, res);

        sort(res);

        std::vector<vector<int>> finish;
        for (int i{}; i < res.size(); ++i) {
            finish.push_back(mp[res[i]]);
        }
        return finish;
    }
};
