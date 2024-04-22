//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool dfs(int i,vector<int>& vis,vector<int>&path,vector<int> adj[])
   {
       vis[i]=1;
       path[i]=1;
       for(auto j:adj[i])
       {
            if( vis[j]==1 && path[j]==1)
           {
               return true;//if both visited it mean cycle pressent as in same path
           }
           if(!vis[j])
           {
               dfs(j,vis,path,adj);
            //   {
            //       return true;
            //   }//else continue searching
           }
            if( vis[j]==1 && path[j]==1)
           {
               return true;//if both visited it mean cycle pressent as in same path
           }
          
       }
       path[i]=0;//while backtracking make path = 0
       return false;
   }
    bool isCyclic(int V, vector<int> adj[]) {
        //visited
        vector<int>vis(V);
        //path visited
        vector<int>path(V);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(i,vis,path,adj)==true)
                {
                    return true;//cycle present 
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends