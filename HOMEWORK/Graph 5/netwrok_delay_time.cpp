class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //adjacency list for directed graph
    unordered_map<int,vector<pair<int,int>>> m;
    for(int i=0;i<times.size();i++)

    {
        m[times[i][0]].push_back({times[i][1],times[i][2]});
    }
    queue<pair<int,int>> q;
    q.push({0,k});//dist,node
    vector<int>ans(n+1,INT_MAX);
    ans[k]=0;
    while(!q.empty())
    {
        auto x=q.front();
        int r=x.first;//dis
        int c=x.second;//node
        q.pop();
        if(r>ans[c])
        {
            continue;
        }
        for (auto i : m[c]) {
   
    if (i.second + r < ans[i.first]) {
        ans[i.first] = i.second + r;
        q.push({i.second + r, i.first});
    }
}
    }
   int maxi=-1;
   for(int i=1;i<ans.size();i++)
   {
    if(ans[i]>maxi)
    {
        maxi=ans[i];
    }
   }
   if(maxi==INT_MAX)
   {
    return -1;
   }
   return maxi;
        
    }
};