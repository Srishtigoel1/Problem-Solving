/{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int>indegree(V,0);//indegree vector
      for(int i=0;i<V;i++)
      {
          for(auto j:adj[i])
          {
              indegree[i]++;
          }
      }
      queue<int>q;
      for(int i =0;i<indegree.size();i++)
      {
          if(indegree[i]==0)
          {
              q.push(i);
          }
      }
      int c=0;
      while(!q.empty())
      {
          auto x=q.front();
          q.pop();
          c++;
          for(auto i:adj[x])
          {
              indegree[i]--;
              if(indegree[i]==0)
              {
                  q.push(i);
              }
          }
      }
      if(c==V)
      {
          return false;
      }
      return true;
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