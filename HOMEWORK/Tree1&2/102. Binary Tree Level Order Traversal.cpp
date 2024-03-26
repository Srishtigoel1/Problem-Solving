/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> a;
        if(root==NULL)
        {
            return a;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto size=q.size();
            vector<int>ans;
            for(int i=0;i<size;i++)
            {
                auto x=q.front();
                q.pop();
                ans.push_back(x->val);
                if(x->left!=NULL)
                {
                    q.push(x->left);
                }
                if(x->right!=NULL)
                {
                    q.push(x->right);
                }
            }
            a.push_back(ans);
        }
        return a;
        
    }
};