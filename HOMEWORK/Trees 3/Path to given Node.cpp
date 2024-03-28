/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool dfs(vector<int>&res,TreeNode* A,int B)
 {
     if(A==NULL)
     {
         return false;
     }
     res.push_back(A->val);
     if( A->val==B)
     {
       return true;
     }
     
     if(dfs(res,A->left,B) || dfs(res,A->right,B))
     {
         return true;
     }
     res.pop_back();
     return false;
   
     
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>res;
    if(A==NULL)
    {
        return res;
    }
    
    dfs(res,A,B);
    return res;
}
