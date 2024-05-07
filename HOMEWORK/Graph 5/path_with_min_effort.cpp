class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=heights.size();//row
        int m=heights[0].size();//column
        pq.push({0,{0,0}});
        int X[]={-1,0,0,1};
        int Y[]={0,-1,1,0};
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        int effort;
        while(!pq.empty())
        {
            auto p=pq.top();
            int diff=p.first;
            int row=p.second.first;
            int col=p.second.second;
            pq.pop();
            if(row==n-1 && col==m-1)
            {
                return diff;
            }
            for(int i=0;i<4;i++)
            {
                auto nr=row+X[i];
                auto nc=col+Y[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    effort=max(diff,abs(heights[row][col]-heights[nr][nc]));
                    if(effort<dist[nr][nc])
                    {
                        dist[nr][nc]=effort;
                        pq.push({effort,{nr,nc}});
                    }
                }
            }



        }
        return 0;
    }
    
};