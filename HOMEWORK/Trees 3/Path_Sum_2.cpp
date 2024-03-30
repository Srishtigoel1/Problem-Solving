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
void dfs(TreeNode* root,vector<vector<int>>&ans,vector<int>&a,int target)
{
    if(root==NULL)
    {
        return;
    }
    a.push_back(root->val);
    if(root->left==NULL && root->right==NULL && target==root->val)
    {
        ans.push_back(a);
    }
    dfs(root->left,ans,a,target-root->val);
    dfs(root->right,ans,a,target-root->val);
    a.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>>ans;
        vector<int>a;
        dfs(root,ans,a,target);
        return ans;
        
    }
};