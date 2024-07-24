// Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/

// Algprithm 
// 1. Create 3 , 2-D Boolena Matrices to validate unique Row , Column and SubArea Entries

// 2. Traverse the Complete Board 
// 3. If '.' is found we skip the iteration 
// 4. Calculate the Index by extracting the element from the Board 
// 5. Calculate the SubArea by s = (i/3)*3 + (j/3) 
// 6. Check if the value in any of the 3 matrices is true for the index
// 7. If yes -> return False 
// 8.  If no -> Add the Index entry to all the Matrices

// 9. If no repititions found -> return True

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