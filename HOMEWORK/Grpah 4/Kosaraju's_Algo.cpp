//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int i,vector<vector<int>> & adj,vector<int>& vis,stack<int>& st)
	{
	    vis[i]=1;
	    for(auto j:adj[i])
	    {
	        if(!vis[j])
	        {
	            dfs(j,adj,vis,st);
	        }
	    }
	    st.push(i);
	}
		void help(int i,unordered_map<int,vector<int>> & adjtranspose,vector<int>& vis2)
	{
	    vis2[i]=1;
	    for(auto j:adjtranspose[i])
	    {
	        if(!vis2[j])
	        {
	            help(j,adjtranspose,vis2);
	        }
	    }
	    
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
      //visited 
      vector<int> vis(V,0);
      stack<int>st;
      for(int i=0;i<V;i++)
      
      {
          if(!vis[i])
          {
              dfs(i,adj,vis,st);
          }
      }
      //reverse graph 
     unordered_map<int,vector<int>> adjtranspose;
      for(int i=0;i<V;i++)
      {
          for(auto j:adj[i])
          {
              adjtranspose[j].push_back(i);
          }
      }
      vector<int>vis2(V,0);
      int c=0;
      while(st.empty()==false)
      {
          auto x=st.top();
          if(vis2[x]==0)
          {
              c++;
              help(x,adjtranspose,vis2);
              st.pop();
          }
          else
          {
              st.pop();
          }
      }
      return c;
      /*
      so basically approach was to find the element of the SCC1 for that we runned dfs and stored element in stack
      then we got to know that top element is the element from which SCC1 start 
      then we reversed the edges 
      as SCC-->reverse---> SCC
      !SCC--->reverse---->!SCC
      then we again run dfs to find the number f SCC componenets
      */
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends