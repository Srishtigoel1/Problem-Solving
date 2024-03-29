/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
bool dfs(vector<TreeNode*>&res,TreeNode* root,TreeNode* p)
{
      if(root==NULL)
      {
        return false;
      }
      res.push_back(root);
      if(root==p)
      {
        return true;
      }
      
      if(dfs(res,root->left,p) || dfs(res,root->right,p))
      {
        return true;
      }
      res.pop_back();
      return false;

}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root==NULL)
        // {
        //     return NULL;
        // }
        // if(root==p && root==q)
        // {
        //     return root;
        // }
        vector<TreeNode*>res;
        dfs(res,root,p);
        vector<TreeNode*>k;
        dfs(k,root,q);
        int i=res.size()-1;
        int j=k.size()-1;
        for(int i=res.size()-1;i>=0;i--)
        {
            if(find(k.begin(),k.end(),res[i])!=k.end())
            {
                return res[i];
                //this is the common point didnt run while loop as not sure whether the number of
                //elements in paths are same or not
            }

        }

        return nullptr;
        
    }
};