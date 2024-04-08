class Solution {
    void inorder(TreeNode* root,int low,int high,int &sum)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,low,high,sum);
        if(root->val>=low && root->val<=high)
        {
            sum=sum+root->val;
        }
        inorder(root->right,low,high,sum);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        inorder(root,low,high,sum);
        return sum;
        
    }
};