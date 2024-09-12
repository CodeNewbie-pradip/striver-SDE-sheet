/*
GFG Link               : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1 
GFG Problem difficulty : Hard
GFG Related Topic      : Graph, DFS, 
Medium Article Link    : https://medium.com/@pradipalabade/how-to-graph-traverse-7a6918f64bc8
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: Brute Force Recursive Approach generate all subset sum
//T.C       : O(n^2)
//S.C       : O(n^2)
//-------------------------------------------------------------------------------------------------------------
class Solution {
  public:
  
    void subset(int ind, int sum, vector<int>& arr, int n, vector<int>& subsum){
        if(ind==n){
            subsum.push_back(sum);
            return;
        }
        
        subset(ind+1, sum+arr[ind], arr, n, subsum);
        
        subset(ind+1, sum, arr, n, subsum);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> subsum;
        subset(0, 0, arr, n, subsum);
        return subsum;
    }
};

//------------------------------Solution - in - java -----------------------------------------------------------

//Approach 1: Brute Force Recursive Approach generate all subset sum
//T.C       : O(n^2)
//S.C       : O(n^2)
//-------------------------------------------------------------------------------------------------------------
class Solution {
    public void subset(int ind, int sum, int[] arr, int n, List<Integer> subsum) {
        if (ind == n) {
            subsum.add(sum);
            return;
        }

        subset(ind + 1, sum + arr[ind], arr, n, subsum);
        subset(ind + 1, sum, arr, n, subsum);
    }

    public List<Integer> subsetSums(int[] arr, int n) {
        List<Integer> subsum = new ArrayList<>();
        subset(0, 0, arr, n, subsum);
        return subsum;
    }
//-------------------------------------------------------------------------------------------------------------