// Spiral Matrix
// https://leetcode.com/problems/spiral-matrix/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int total = matrix.size() * matrix[0].size();
        int count = 0 ;
        vector<int> ans ;
        int startRow = 0 ;
        int startCol = 0 ;
        int endRow = matrix.size()-1 ;
        int endCol = matrix[0].size()-1 ;
        while(count < total){
            for(int i = startCol ; i<=endCol && count < total ; i++){
                ans.push_back(matrix[startRow][i]);
                count++ ;
            }
            startRow++ ;
            for(int i = startRow ; i<=endRow && count < total ; i++){
                ans.push_back(matrix[i][endCol]);
                count++ ;
            }
            endCol-- ;
            for(int i = endCol ; i>=startCol && count < total ; i--){
                ans.push_back(matrix[endRow][i]);
                count++ ;
            }
            endRow-- ;
            for(int i = endRow ; i>=startRow && count < total ; i--){
                ans.push_back(matrix[i][startCol]);
                count++ ;
            }
            startCol++ ;
        }
        return ans ;
    }