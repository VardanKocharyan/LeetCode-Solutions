class Solution {
public:
    // void print(std::vector<std::vector<char>>& board) {
    //     for (const std::vector<char> v : board) {
    //         for (const char ch : v) {
    //             std::cout << ch << " ";
    //         }
    //         std::cout << '\n';
    //     }
    //     std::cout << "\n\n";
    // }
    bool isValid(int i, int j, char target, std::vector<std::vector<char>>& board) {
        return (i >= 0 && i < board.size()) && (j >= 0 && j < board[0].size()) && (board[i][j] != '$') && board[i][j] == target;
    }

    bool dfs(int i, int j, int pos, std::vector<int>& steps, std::string word, std::vector<std::vector<char>>& board) {
        if (pos == word.length() - 1) return true;

        char key = board[i][j];
        board[i][j] = '$';

        // std::cout << "\tI : " << i << " J: " << j << " POS:" << pos << std::endl;
        // print(board);

        for (int k{1}; k < steps.size(); ++k)
            if (isValid(i + steps[k - 1], j + steps[k], word[pos + 1], board) && dfs(i + steps[k - 1], j + steps[k], pos + 1, steps, word, board)) return true;
        
        board[i][j] = key;
        
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        std::vector<int> steps({-1, 0, 1, 0, -1});
        int n = board.size();
        int m = board[0].size();

        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                if (word[0] == board[i][j] && dfs(i, j, 0, steps, word, board)) return true; 
            }
        }

        return false;
    }
};
