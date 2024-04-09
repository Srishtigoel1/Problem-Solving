//one approach 

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
void inorder(TreeNode* root, vector<int>& ans)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
       return ans[k-1];
        
    }
};

//second approach

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
int value;
void solve(TreeNode* root,int& c,int k)
{
    if(root==NULL || c>=k)
    {
        return;
    }
    solve(root->left,c,k);
    c++;
    if(c==k)
    {
        value=root->val;//whenever we get c==k store that value
        return;
    }
    solve(root->right,c,k);
}
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        value=-1;
        solve(root,c,k);
        return value;
        
    }
};