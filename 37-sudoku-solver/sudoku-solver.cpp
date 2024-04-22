class Solution {
public:
    bool isSafe(int i, int j, vector<vector<char>>& board, int value) {

        for (int k = 0; k < 9; k++) {
            
            if (board[i][k] == value)
                return false;
            
            if (board[k][j] == value)
                return false;
            
            if (board[3 * (i / 3) + (k / 3)][3 * (j / 3) + (k % 3)] == value)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               
                if (board[i][j] == '.') {
               
                    for (char value = '1'; value <= '9'; value++) {
                       
                        if (isSafe(i, j, board, value)) {
                            board[i][j] = value;
                         
                            if (solve(board) == true)
                                return true;
                           
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};
