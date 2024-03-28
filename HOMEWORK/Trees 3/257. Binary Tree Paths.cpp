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
void dfs(vector<string>&result,string ans,TreeNode* root)
{
    if(root->left==NULL && root->right==NULL)
    {
        //leaf node
        ans=ans+to_string(root->val);
        result.push_back(ans);
        ans.pop_back();//backtracking
        return;
    }
    ans=ans+to_string(root->val);
    ans=ans+"->";
    if(root->left!=NULL)
    {
        dfs(result,ans,root->left);
    }
    if(root->right!=NULL)
    {
        dfs(result,ans,root->right);
    }
    ans.pop_back();
    ans.pop_back();
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        string ans;
        dfs(result,ans,root);
        //in answer will be storing the possible answers
        return result;
        
    }
};