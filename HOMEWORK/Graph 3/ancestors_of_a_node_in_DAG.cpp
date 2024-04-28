class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
      unordered_map<int,vector<int>> adj;
      vector<set<int>> v(n);//...
      vector<int>indegree(n);
      for(int i=0;i<edges.size();i++)
      {
        adj[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;

      }
      queue<int>q;
      for(int i=0;i<indegree.size();i++)
      {
        if(indegree[i]==0)
        {
            q.push(i);
        }
      }
      vector<vector<int>> ans(n);
      while(!q.empty())
      {
        int x=q.front();
        q.pop();
        for(auto i:adj[x])
        {
            indegree[i]--;
            for(auto j:v[x])
            v[i].insert(j);//
        v[i].insert(x);
        if(indegree[i]==0)
                {
                    q.push(i);
                }
            
        }

      }
      for(int i=0;i<n;i++)
      {
        for(int j:v[i])
        {
            ans[i].push_back(j);
        }
      }
      return ans;

    }
};