/*
InterviewBit Link           : https://www.interviewbit.com/problems/repeat-and-missing-number-array/
InterviewBit difficulty     : Medium
InterviewBit Related Topic  : 
Medium Article Link	        : 
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute Force
//T.C       : O(n)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    int repeating=-1, missing=-1;
    
    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=0; j<n; j++){
            if(A[j]==i){
                cnt++;
            }
        }
        if(cnt==2) repeating=i;
        if(cnt==0) missing=i;
        
        if(repeating!=-1 && missing!=-1){
            break;
        }
    }
    return {repeating, missing};
}

//-----------------------------------------------------------------------------------------------------------------
//Approach 2: Math
//T.C       : O(n)
//S.C       : O(1)
//-----------------------------------------------------------------------------------------------------------------
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n=A.size();
    
    long long sn=(n*(n+1))/2;
    long long s2n=(n*(n+1)*(2*n+1))/6;
    
    long long an=0, a2n=0;
    for(int i=0; i<n; i++){
        an+=A[i];
        a2n+=(long long)A[i]*(long long)A[i];
    }
    
    long long val1=an-sn;
    long long val2=a2n-s2n;
    
    val2=val2/val1;
    
    long long x=(val1+val2)/2;
    long long y=x-val1;
    
    return {(int)x, (int)y};
}

//---------------------------------------------------------------------------------
