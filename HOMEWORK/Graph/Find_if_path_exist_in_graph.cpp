class Solution {
public:
bool bfs(unordered_map<int,vector<int>>&m,int s,int d,vector<int>&vis)
{
    vis[s]=1;
    queue<int>q;
    q.push(s);
    if(s==d)
    {
        return true;
    }
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        for(auto k:m[x])
        {
            if(k==d)
            {
                return true;
            }
            if(!vis[k])
            {
                vis[k]=1;
                q.push(k);
            }
        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //adjacency list for undirected graph
        unordered_map<int,vector<int>>m;
        for(int i=0;i<edges.size();i++)
        {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n);
        for(int i=0;i<n;i++){
        if(bfs(m,source,destination,vis))
        {
            return true;
        }
        }
        return false;
        
    }
};