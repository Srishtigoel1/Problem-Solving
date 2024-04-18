class Solution {
public:
void helper(unordered_map<int,vector<int>>&adj,vector<int>&visited,int start,unordered_map<int,int>&ans){
    queue<int>q;
    q.push(start);
    visited[start]=1;
    ans[start]++;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it : adj[x]){
            if(ans.find(it)!=ans.end()){
                //mil gya
                ans.erase(it);
            }
            if(visited[it]==0){
                visited[it]=1;
                q.push(it);
            }
        }
    }

}
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);//visited array
        unordered_map<int,int>ans;//for storing

        unordered_map<int,vector<int>>adj;//adjacency
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);//directed adjacency list
        }

        for(int i=0;i<n;i++){
            if(visited[i]==0){

            helper(adj,visited,i,ans);
            }
        }
        vector<int>vec;
        for(auto it=ans.begin();it!=ans.end();it++){
            vec.push_back(it->first);
        }
        
        return vec;
    }
};