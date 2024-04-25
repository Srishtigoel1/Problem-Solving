class Solution {
public:
 vector<int> findOrder(int c, vector<vector<int>>& prerequisites) {
        //adjacency list
        vector<int>adj[c];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        //indegree
        vector<int>indegree(c);
        for(int i=0;i<c;i++)
        {
            for(auto j:adj[i])
            {
                indegree[j]++;
            }
        }
        //topological sort
        queue<int>q;
        for(int i=0;i<c;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        int ct=0;
        while(!q.empty())
        {
            auto x=q.front();
            ans.push_back(x);
            ct++;
            q.pop();
            for(auto j:adj[x])
            {
                indegree[j]--;
                if(indegree[j]==0)
                {
                    q.push(j);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        if(c==ct)
        {
            return ans;
        }
        ans.clear();
        return ans;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int>y;
        y=findOrder(numCourses,prerequisites);
        if(y.size()==0)
        {
            return false;
        }
        return true;
    }
};