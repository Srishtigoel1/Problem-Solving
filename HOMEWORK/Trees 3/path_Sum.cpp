/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(NULL), right(NULL) {}
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
                return false;
            } 
            if (root->left == NULL && root->right == NULL && root->val == targetSum) {
                return true;
            }
            bool leftPath = hasPathSum(root->left, targetSum - root->val);
            bool rightPath = hasPathSum(root->right, targetSum - root->val);
            return leftPath || rightPath;
            
        }
};