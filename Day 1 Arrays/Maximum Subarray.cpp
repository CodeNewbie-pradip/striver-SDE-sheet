/*
Leetcode Link               : https://leetcode.com/problems/maximum-subarray/
Leetcode difficulty         : Medium
Leetcode Related Topic      : Arrays, Divide & conquer, Dynamic Programming
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Kadane's Algorithm (Greedy Approach)
//T.C       : O(n)
//S.C       : O(1)

//-------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currSum=0;
        int maxSum=INT_MIN;
        
        for(auto num:nums){
            currSum=max(num, currSum+num);
            maxSum=max(maxSum, currSum);
        }
        
        return maxSum;
    }
};

//----------------------------------------------------------------------------------------------------------------
//Approach 2: Kadane's Algorithm (Greedy Approach)
//T.C       : O(n)
//S.C       : O(1)

//-------------------------------------------------------------------------------------------------------------