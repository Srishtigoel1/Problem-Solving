class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        //adjacency list for undirected graph 
        unordered_map<int,vector<pair<int,int>>>m;
        for(int i=0;i<edges.size();i++)
        {
            m[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            m[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
      queue<pair<int,int>> q;//can also use min heap(priority queue)
        q.push({0,0});//node , dist
        vector<int> ans(n,INT_MAX);
        ans[0]=0;
        while(!q.empty())
        {
            auto x=q.front();
            int r=x.first;
            int c=x.second;
            q.pop();
            if (c > ans[r]) continue;//yeh node pehle hi kissi chotte distance se pahuch chukki h
            for(auto i : m[r])
            {
                if(i.second+c<ans[i.first] && i.second+c<disappear[i.first])
                {
                    ans[i.first]=i.second+c;
                    q.push({i.first,ans[i.first]});
                }
            }

        }
for(int i=0;i<ans.size();i++)
{
    if(ans[i]==INT_MAX)
    ans[i]=-1;
}
return ans;
        
    }
};