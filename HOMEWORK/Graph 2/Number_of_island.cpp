class Solution {
public:
void bfs(vector<vector<int>>&vis,vector<vector<char>>&grid,int i,int j)
{
    queue<pair<int,int>>q;
    q.push({i,j});
    vis[i][j]=1;
    int x[]={-1,1,0,0};
    int y[]={0,0,-1,1};
    int n=grid.size();
    int m=grid[0].size();
    while(!q.empty())
    {
        auto o=q.front();
        auto r=o.first;
        auto c=o.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            auto nr=r+x[i];
            auto nc=c+y[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]=='1')
            {
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }

    }
}
    int numIslands(vector<vector<char>>& grid) {
        //visited matrix
        int n=grid.size();//row;
        int m=grid[0].size();//col
        vector<vector<int>>vis(n,vector<int>(m,0));
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]!=1 && grid[i][j]=='1')
                {
                    bfs(vis,grid,i,j);
                    c++;
                }
            }
        }
        return c;
        
    }
};