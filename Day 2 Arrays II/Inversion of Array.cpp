/*
Coding Ninjas Link          : https://www.naukri.com/code360/problems/count-inversions_615?leftPanelTabValue=PROBLEM
Coding Ninjas difficulty    : Medium
Coding Ninjas Related Topic : 
Medium Article Link	        : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute Force
//T.C       : O(n)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    // Write your code here.
    long long ans=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
            {
                    ans++;
                }
            }
        }
    return ans;
}

//--------------------------------------------------------------------------------------------------------------