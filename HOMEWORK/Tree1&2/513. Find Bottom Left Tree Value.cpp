class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty())
        {
            int level=q.size();
            vector<int>lev;
            for(int i=0;i<level;i++){
            auto x=q.front();
            q.pop();
            lev.push_back(x->val);
            if(x->left)
            {
                q.push(x->left);
            }
            if(x->right)
            {
                q.push(x->right);
            }
            }
            ans.push_back(lev);

        }
        auto n=ans.size();
        return ans[n-1][0];
        
    }
};