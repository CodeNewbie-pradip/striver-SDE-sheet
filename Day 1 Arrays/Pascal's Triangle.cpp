/*
Leetcode Link               : https://leetcode.com/problems/pascals-triangle/
Leetcode difficulty         : EASY
Leetcode Related Topic      : Arrays, DP
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Iterative Approach Using Nested Loops
//T.C       : O(numRows^2)
//S.C       : O(numRows^2)

//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result(numRows);
        
        for(int i=0; i<numRows; i++){
            result[i].resize(i+1);
            result[i][0]=result[i][i]=1;
            for(int j=1; j<i; j++){
                result[i][j]=result[i-1][j-1]+result[i-1][j];
            }
        }
        return result;
    }
};

//------------------------------------------------------------------------------------------------------------------

//Approach 2: Dynamic Programming
//T.C       : O(numRows^2)
//S.C       : O(numRows^2)

//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        
        for(int i=1; i<=numRows; i++){
            vector<int>v(i,1);
            
            if(i>2){
                for(int j=1; j<=v.size()-2; j++){
                    v[j]=result[result.size()-1][j-1]+result[result.size()-1][j];
                }
            }
            result.push_back(v);
        }
        return result;
    }
};
//------------------------------------------------------------------------------------------------------------------
//Approach 3: Dynamic Programming
//T.C       : O(numRows^2)
//S.C       : O(numRows)

//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        vector<int>row;
        for(int i=0; i<numRows; i++){
            row.push_back(1);
            for(int j=i-1; j>0; j--){
                row[j]+=row[j-1];
            }
            result.push_back(row);
        }
        return result;
    }
};
//-------------------------------------------------------------------------------------------------------------
//Approach 4: Recursive method
//T.C       : O(numRows^2)
//S.C       : O(numRows^2)

//-------------------------------------------------------------------------------------------------------------
class Solution{
    public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};

        vector<int> previousRow = getRow(rowIndex - 1);
        vector<int> currentRow(rowIndex + 1, 1);

        for (int i = 1; i < rowIndex; ++i) {
            currentRow[i] = previousRow[i - 1] + previousRow[i];
        }

        return currentRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; ++i) {
            result.push_back(getRow(i));
        }

        return result;
    }
};
//-------------------------------------------------------------------------------------------------------------