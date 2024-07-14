// Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

bool isValidSudoku(vector<vector<char>>& board) {
        const int count = 9;
        bool r[count][count] = {false};
        bool c[count][count] = {false};
        bool s[count][count] = {false};
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == '.') {
                    continue;
                }
                int index = board[row][col] - '0' - 1;
                int area = (row / 3) * 3 + (col / 3);
                if (r[row][index] || c[col][index] || s[area][index]) {
                    return false;
                }
                r[row][index] = true;
                c[col][index] = true;
                s[area][index] = true;
            }
        }
        return true;
    }