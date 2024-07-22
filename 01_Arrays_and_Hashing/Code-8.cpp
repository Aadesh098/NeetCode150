// Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

bool isValidSudoku(vector<vector<char>>& board) {
        const int count = 9;
        bool r[count][count] = {false};
        bool c[count][count] = {false};
        bool s[count][count] = {false};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int index = board[i][j] - '0' - 1;
                int area = (i / 3) * 3 + (j / 3);
                if (r[i][index] || c[j][index] || s[area][index]) {
                    return false;
                }
                r[i][index] = true;
                c[j][index] = true;
                s[area][index] = true;
            }
        }
        return true;
    }