#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int d)
    {
        this->val=d;
        this->right=NULL;
        this->left=NULL;
    }
};
TreeNode* buildtree(TreeNode* root)
{
    cout<<"Enter tha value of node"<<endl;
    int n;
    cin>>n;
    if(n==-1)
    {
        return NULL;
    }
    root=new TreeNode(n);
    cout<<"Enter the left node"<<endl;
    root->left=buildtree(root->left);
     cout<<"Enter the right node"<<endl;
     root->right=buildtree(root->right);

}
void levelorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        queue<TreeNode *>q;
        q.push(root);//pehla element daal diya
        vector<int>ans;
        while(!q.empty())
        {
            auto x=q.front();
            ans.push_back(x->val);
            q.pop();
            if(x->left!=NULL)
            {
                q.push(x->left);
            }
            if(x->right!=NULL)
            {
                q.push(x->right);
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
    }
   
bool solve(TreeNode* root,long long int maxi,long long int mini)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->val>=maxi || root->val<=mini)
    {
        return false;
    }
    bool x=solve(root->left,root->val,mini);
    bool y=solve(root->right,maxi,root->val);
    return x&&y;
}
   

int main()
{
    TreeNode* root=NULL;
    root=buildtree(root);
    levelorder(root);
    cout<<endl<<endl;
    cout<<"IS BST?"<<endl;
    cout<<solve(root,LONG_MAX,LONG_MIN);
}