class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,int>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        vector<int>ans;
        while(!q.empty())
        {
            auto x=q.front();
            if(m.find(x.second)==m.end())
            {
                m[x.second]=x.first->data;
            }
            q.pop();
            if(x.first->left)
            {
                q.push({x.first->left,x.second-1});
            }
             if(x.first->right)
            {
                q.push({x.first->right,x.second+1});
            }
        }
        for(auto i=m.begin();i!=m.end();i++)
        {
            ans.push_back(i->second);
        }
        return ans;
    }

};