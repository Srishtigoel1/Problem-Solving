class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        //question was easy just writing specifically by considering data type and all needed concentration
        //undirected weighted graph
        unordered_map<int,vector<pair<int,double>>> m;
        for(int i=0;i<edges.size();i++)
        {
            m[edges[i][0]].push_back({edges[i][1],succProb[i]});
            m[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>ans(n,0);
       priority_queue<pair<double,int>> q;//probability , node
        q.push({1.0,start_node});
        ans[start_node]=1;
        while(!q.empty())
        {
            auto x=q.top();
            q.pop();
            double prob=x.first;
            int ele=x.second;
            for(auto i: m[ele])
            {
                if(prob*i.second>ans[i.first])
                {
                    ans[i.first]=prob*i.second;
                    q.push({ans[i.first],i.first});
                }
            }

        }
     
        return ans[end_node];
    }
};