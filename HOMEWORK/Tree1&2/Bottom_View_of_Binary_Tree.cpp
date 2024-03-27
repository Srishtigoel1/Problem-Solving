class Solution {
  public:
    vector <int> bottomView(Node *root) {
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>m;
        while(!q.empty())
        {
            auto x=q.front();
            auto y=x.first;
            auto t=x.second;
            q.pop();
            m[t]=y->data;
            if(y->left!=NULL)
            {
                q.push({y->left,t-1});
            }
            if(y->right!=NULL)
            {
                q.push({y->right,t+1});
            }
        }
        vector<int>ans;
        for(auto i=m.begin();i!=m.end();i++)
        {
            ans.push_back(i->second);
        }
        return ans;
    }
};