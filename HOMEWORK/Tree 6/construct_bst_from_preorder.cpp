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
int find(vector<int> in , int element, int size)
{
    for(int i=0;i<size;i++)
    {
        if(in[i]==element)
        {
            return i;
        }
    }
    return -1;
}
TreeNode *solve(vector<int>in,vector<int>pre,int &index,int instart,int inend,int size)
{
    if(index>=size|| instart>inend)
    {
        return NULL;
    }
    int element=pre[index++];
    TreeNode* root=new TreeNode(element);
    int position=find(in,element,size);
    root->left=solve(in,pre,index,instart,position-1,size);
    root->right=solve(in,pre,index,position+1,inend,size);
    return root;


}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>in;
        for(int i=0;i<preorder.size();i++)
        {
            in.push_back(preorder[i]);

        }
        sort(in.begin(),in.end());
        int preorderindex=0;
        int n=preorder.size();
        TreeNode* ans=solve(in,preorder,preorderindex,0,n-1,n);
        return ans;

        
    }
};