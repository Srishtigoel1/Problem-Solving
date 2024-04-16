class Solution {
public:
void bfs(unordered_map<int,vector<int>>&m,int i,vector<int>&vis)
{
    queue<int>q;
    q.push(i);
    vis[i]=1;
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        for(auto j:m[x])
        {
            if(!vis[j])
            {
                vis[j]=1;
                q.push(j);
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        //adjacency list
        unordered_map<int,vector<int>>m;
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j]==1 && i!=j){
                m[i].push_back(j);
                m[j].push_back(i);
                }
            }
        }
        int n=isConnected.size();
        vector<int>vis(n,0);
        int c=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(!vis[i]){
            bfs(m,i,vis);
            c++;
            }
        }
        return c;
    }
};