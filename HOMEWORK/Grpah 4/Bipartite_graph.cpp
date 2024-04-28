class Solution {
public:
bool bfs(vector<vector<int>>& graph,int i,vector<int>&color)
{
    queue<int>q;
    q.push(i);
    if(color[i]==-1)
    {
        //colored
    color[i]=0;
    }
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        for(auto j:graph[x])//adj of that x 
        {
            if(color[j]==-1){
                //abhi tk color ni kiya 
            color[j]=abs(color[x]-1);
            q.push(j);
           
            }
            else if(color[j]==color[x])
            {
                //pr agar colored h ...aur uska adjacent bhi same then return false;
                return false;
            }
             
            
        }

    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();//row;
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                //abhi tk color ni kiya h
                if(bfs(graph,i,color)==false)
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};