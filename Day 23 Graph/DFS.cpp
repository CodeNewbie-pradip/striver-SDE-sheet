/*
GFG Link               : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1 
GFG Problem difficulty : Hard
GFG Related Topic      : Graph, DFS, 
Medium Article Link    : https://medium.com/@pradipalabade/how-to-graph-traverse-7a6918f64bc8
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: DFS Traversal
//T.C       : O(n)
//S.C       : O(n)
//-------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int vertex, vector<int>&vis, vector<int>&ans, vector<int> adj[]){
        vis[vertex]=true;
        ans.push_back(vertex);
        for(auto child: adj[vertex]){
        if(vis[child]==false){
                dfs(child, vis, ans, adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V, false);
        vector<int>ans;
        
        dfs(0, vis, ans, adj);
        
        return ans;
    }
};
//-------------------------------------------------------------------------------------------------------------
