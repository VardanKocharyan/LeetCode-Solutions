class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       int i{}, j{};

       if (word1.empty()) return word2;
       if(word2.empty()) return word1;

       std::string merge;

        while (word1[i] || word2[j]) {
            if (word1[i]) {
                merge.push_back(word1[i++]);
            }
            if (word2[j]) {
                merge.push_back(word2[j++]);
            }
        }
        return merge;
    }
};
