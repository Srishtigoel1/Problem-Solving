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
   
    bool dfs(TreeNode* node,int k,unordered_set<int>& st) {
        if (!node){ 
        return false;
        }
        int y = k - node->val;

        if (st.find(y) != st.end()){
            return true;
        } 
        else{
            st.insert(node->val);
        }
        
        return dfs(node->left,k,st) || dfs(node->right,k,st); 
    }
class Solution {
public:
    bool findTarget(TreeNode* root,int k) {
        unordered_set<int> st;
          return dfs(root,k,st);
    
    }
};