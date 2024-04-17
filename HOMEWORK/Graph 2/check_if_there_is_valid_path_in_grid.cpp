class Solution {
public:
bool bfs(vector<vector<int>>& grid,vector<vector<int>>&vis,int i,int j)
{
    int n=grid.size();//row
    int m=grid[0].size();//col
    queue<pair<int,int>>q;
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty())
    {
        auto o=q.front();
        auto x=o.first;
        auto y=o.second;
        q.pop();
        if(x==n-1 && y==m-1 && vis[n-1][m-1]==1)
        {
            return true;
        }
        if(grid[x][y]==1)
        {
            //right--->y+1
            if(y+1>=0 && y+1<m && vis[x][y+1]!=1 && (grid[x][y+1]==1 || grid[x][y+1]==3 || grid[x][y+1]==5))
        {
            q.push({x,y+1});
            vis[x][y+1]=1;
        }
        //left-->y-1
         if(y-1>=0 && y-1<m && vis[x][y-1]!=1 && (grid[x][y-1]==1 || grid[x][y-1]==4 || grid[x][y-1]==6))
        {
            q.push({x,y-1});
            vis[x][y-1]=1;
        }
        }

        if(grid[x][y]==2)
        {
            //up--->x-1
            if(x-1>=0 && x-1<n && vis[x-1][y]!=1 && (grid[x-1][y]==2 || grid[x-1][y]==3 || grid[x-1][y]==4))
        {
            q.push({x-1,y});
            vis[x-1][y]=1;
        }
        //down--->x+1
         if(x+1>=0 && x+1<n && vis[x+1][y]!=1 && (grid[x+1][y]==2 || grid[x+1][y]==5 || grid[x+1][y]==6))
        {
            q.push({x+1,y});
            vis[x+1][y]=1;
        }
        }
        /////
         if(grid[x][y]==4)
        {
             //right--->y+1
            if(y+1>=0 && y+1<m && vis[x][y+1]!=1 && (grid[x][y+1]==1 || grid[x][y+1]==3 || grid[x][y+1]==5))
        {
            q.push({x,y+1});
            vis[x][y+1]=1;
        }
        //down-->x+1
         if(x+1>=0 && x+1<n && vis[x+1][y]!=1 && (grid[x+1][y]==2 || grid[x+1][y]==5 || grid[x+1][y]==6))
        {
            q.push({x+1,y});
            vis[x+1][y]=1;
        }
        }
        //////
         if(grid[x][y]==6)
        {
             //right--->y+1
            if(y+1>=0 && y+1<m && vis[x][y+1]!=1 && (grid[x][y+1]==1 || grid[x][y+1]==3 || grid[x][y+1]==5))
        {
            q.push({x,y+1});
            vis[x][y+1]=1;
        }
        //up--->x-1
            if(x-1>=0 && x-1<n && vis[x-1][y]!=1 && (grid[x-1][y]==2 || grid[x-1][y]==3 || grid[x-1][y]==4))
        {
            q.push({x-1,y});
            vis[x-1][y]=1;
        }
        }
        ////
         if(grid[x][y]==3)
        {
            //left-->y-1
         if(y-1>=0 && y-1<m && vis[x][y-1]!=1 && (grid[x][y-1]==1 || grid[x][y-1]==4 || grid[x][y-1]==6))
        {
            q.push({x,y-1});
            vis[x][y-1]=1;
        }
        //down-->x+1
         if(x+1>=0 && x+1<n && vis[x+1][y]!=1 && (grid[x+1][y]==2 || grid[x+1][y]==5 || grid[x+1][y]==6))
        {
            q.push({x+1,y});
            vis[x+1][y]=1;
        }
        }
        //////
         if(grid[x][y]==5)
        {
            //left-->y-1
         if(y-1>=0 && y-1<m && vis[x][y-1]!=1 && (grid[x][y-1]==1 || grid[x][y-1]==4 || grid[x][y-1]==6))
        {
            q.push({x,y-1});
            vis[x][y-1]=1;
        }
         //up--->x-1
            if(x-1>=0 && x-1<n && vis[x-1][y]!=1 && (grid[x-1][y]==2 || grid[x-1][y]==3 || grid[x-1][y]==4))
        {
            q.push({x-1,y});
            vis[x-1][y]=1;
        }
        }


    }
    return false;
}
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
      if(bfs(grid,vis,0,0))
      {
        return true;
      }
      return false;

        
    }
};