class Solution {
public:
int find (int i,vector<int>&parent)
{
    if(i==parent[i])
    {
        return i;
    }
    return parent[i]=find(parent[i],parent);
}
void Unionfun(int x,int y,vector<int>&parent)
{
    int parent_x=find(x,parent);
    int parent_y=find(y,parent);
    if (parent_x==parent_y)
    {
        return ;
    }
    parent[parent_x]=parent_y;
   

}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(edges.size()+1);
        for(int i=0;i<parent.size();i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++)
        {
            if(find(edges[i][0],parent)==find(edges[i][1],parent))
            {
               //cycle
            return{edges[i][0],edges[i][1]};
            }
          else
           Unionfun(edges[i][0],edges[i][1],parent);
           
        }
        return {-1,-1};
        
    }
};