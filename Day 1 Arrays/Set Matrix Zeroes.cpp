/*
Leetcode Link               : https://leetcode.com/problems/set-matrix-zeroes/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Arrays, Hash Table, Matrix
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Using Additional Memory (O(m + n) Space)
//T.C       : O(M.N)
//S.C       : O(1)

//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<int> rows(m, false);
        vector<int> cols(n, false);
        
        
        //First pass: Mark the row and column thant need to be set to 0.
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(matrix[i][j]==0){
                    rows[i]=true;
                    cols[j]=true;
                }
            }
        }
        
        //second Pass:Set the matrix cells to 0 based on rows and cols arrays
        for(int i=0; i<m; i++){
            if(rows[i]){
                for(int j=0; j<n; j++){
                    matrix[i][j]=0;
                }
            }
        }
        
        //here we are entire col mark it 0
        for(int i=0; i<n; i++){
            if(cols[i]){
                for(int j=0; j<m; j++){
                    matrix[j][i]=0;
                }
            }
        }
        
    }
};

//------------------------------------------------------------------------------------------------------------------

//Approach 2: Optimized In-Place Solution Using First Row and Column (O(1) Space)
//T.C       : O(M.N)
//S.C       : O(1)

//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
int m = matrix.size();
    int n = matrix[0].size();
    bool firstRowZero = false, firstColZero = false;

    // Check if the first row or first column should be zero
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
    for (int j = 0; j < n; ++j) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    // Use the first row and first column as markers
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set the matrix cells to zero based on markers
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Finally, set the first row and first column to zero if needed
    if (firstRowZero) {
        for (int j = 0; j < n; ++j) {
            matrix[0][j] = 0;
        }
    }
    if (firstColZero) {
        for (int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }
        
    }
};
//------------------------------------------------------------------------------------------------------------------
