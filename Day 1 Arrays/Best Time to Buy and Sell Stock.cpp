/*
Leetcode Link               : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
Leetcode difficulty         : Easy
Leetcode Related Topic      : Arrays
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute Force 
//T.C       : O(N^2)
//S.C       : O(1)
//Error     : TLE
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                maxProfit=max(maxProfit, prices[j]-prices[i]);
            }
        }
        return maxProfit;
    }
};

//------------------------------------------------------------------------------------------------------------------

//Approach 2: Optimized and single Passes
//T.C       : O(n)
//S.C       : O(1)

//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(auto price:prices){
            minPrice=min(minPrice, price);
            maxProfit=max(maxProfit, price-minPrice);
        }
        return maxProfit;
    }
};
//------------------------------------------------------------------------------------------------------------------
