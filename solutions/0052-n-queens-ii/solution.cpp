class Solution {
int count{};
public:
    bool isValid(std::vector<std::string>& board, int i, int j) {
        int n = board.size();

        for (int k{i - 1}; k >= 0; --k) {
            if (board[k][j] == 'Q') return false;
        }

        for (int k{i - 1}, q{j - 1}; k >= 0 && q >= 0; --k, --q) {
            if (board[k][q] == 'Q') return false;
        }

        for (int k{i - 1}, q{j + 1}; k >= 0 && q < n; --k, ++q) {
            if (board[k][q] == 'Q') return false;
        }

        return true;
    }

    void nqueens(int n, std::vector<std::string>& board, int i) {
        if (i >= n) {
            ++count;
            return;
        }

        for (int j{}; j < n; ++j) {
            if (isValid(board, i, j)) {
                board[i][j] = 'Q';
                nqueens(n, board, i + 1);
            }
            board[i][j] = '.';
        }
    }


    int totalNQueens(int n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        nqueens(n, board, 0);

        return count;  
    }
};
