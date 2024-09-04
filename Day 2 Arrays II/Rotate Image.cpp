/*
Leetcode Link               : https://leetcode.com/problems/rotate-image/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Array, Math, Matrix
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute Force 
//T.C       : O(N^2)
//S.C       : O(1)
//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=i+1; j<matrix[i].size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

//--------------------------------------------------------------------------------------------------------------