//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    queue<pair<pair<int,int>,int>>q;
	   vector<vector<int>> vis(n,vector<int>(m,0));//visited 
	   vector<vector<int>> dis(n,vector<int>(m,0));//distance
	   int X[]={-1,0,0,1};
	   int Y[]={0,-1,1,0};
	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<m;j++)
	       {
	           if(grid[i][j]==1){
	           vis[i][j]=1;
	           q.push({{i,j},0});
	           }
	       }
	   }
	   while(!q.empty())
	   {
	       auto x=q.front();
	       auto y=x.first.first;//x coor
	       auto z=x.first.second;//y coor
	       auto d=x.second;//distance 
	       q.pop();
	       vis[y][z]=1;
	       dis[y][z]=d;
	       for(int i=0;i<4;i++)
	       {
	           auto nr=y+X[i];
	           auto nc=z+Y[i];
	           if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0)
	           {
	               vis[nr][nc]=1;
	               q.push({{nr,nc},d+1});
	           }
	       }
	       
	   }
	   return dis;
	   
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends