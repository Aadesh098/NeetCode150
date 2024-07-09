// Binary Search in 2-D Array
// https://leetcode.com/problems/search-a-2d-matrix/

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int startRow = 0;
        int endRow = matrix.size() - 1;     
        while (startRow < endRow) {
            int mid = startRow + (endRow - startRow) / 2;
            if (matrix[mid][0] == target) {
                return true;
            }
            if (matrix[mid][0] < target && target < matrix[mid + 1][0]) {
                startRow = mid;
                break;
            }
            if (matrix[mid][0] < target) {
                startRow = mid + 1;
            } else {
                endRow = mid - 1;
            }
        }
        int startCol = 0;
        int endCol = matrix[0].size() - 1;
        while (startCol <= endCol) {
            int mid = startCol + (endCol - startCol) / 2;
            if (matrix[startRow][mid] == target) {
                return true;
            }
            if (matrix[startRow][mid] < target) {
                startCol = mid + 1;
            } else {
                endCol = mid - 1;
            }
        }
        return false;
    }