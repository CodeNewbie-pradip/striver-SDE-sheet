/*
GFG Link               : https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1 
GFG Problem difficulty : Hard
GFG Related Topic      : Graph, DFS, 
Medium Article Link    : https://medium.com/@pradipalabade/how-to-graph-traverse-7a6918f64bc8
*/

//------------------------------Solution - in - C++ -----------------------------------------------------------

//Approach 1: BFS Traversal
//T.C       : O(V+E)
//S.C       : O(V)
//-------------------------------------------------------------------------------------------------------------
class Solution {
public:
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       // Code here
       vector<int>vis(V, false);
       vector<int>ans;             
       queue<int>q;
       q.push(0);             
       while(!q.empty()){
              int front=q.front();
              q.pop();                 
              if(!vis[front]){
              ans.push_back(front);
              vis[front]=true;
              for(auto child:adj[front]){
                     if(!vis[child]){
                            q.push(child);
                     }
              }
              }
       }
       return ans;
       }
};
//-------------------------------------------------------------------------------------------------------------
