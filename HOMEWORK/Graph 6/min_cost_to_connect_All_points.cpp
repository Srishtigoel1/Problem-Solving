class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //adjacency list 
        map<pair<int,int>,vector<pair<int,pair<int,int>>>> m;
        //x,y --> dist, node 1, node 2
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<points.size();i++)
        {
            for(int j=0;j<points.size();j++)
            {
                if(i!=j)
                {
                    int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                    m[{points[i][0],points[i][1]}].push_back({dis,{points[j][0],points[j][1]}});
                }
            }
        }
        //i will be using map as visited 
        map<pair<int,int>,int>vis;
        pq.push({0,{points[0][0],points[0][1]}});
        int sum=0;
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            if(vis.find({x.second.first,x.second.second})==vis.end())//nhi mila
            {
                vis[{x.second.first,x.second.second}]=1;
                sum+=x.first;
                for(auto i: m[{x.second.first,x.second.second}])
                {
                    if(vis.find({i.second.first,i.second.second})==vis.end())//nhi mila
                    {
                        pq.push({i.first,{i.second.first,i.second.second}});
                    }
                }
            }
        }
        return sum;
        
    }
};