#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//trying to code from scratch..runned these function on online platform
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int d)
    {
        this->val=d;
    }
};
TreeNode* buildtree(TreeNode* root)
{
    cout<<"Enter the value of node"<<endl;
    int n;
    cin>>n;
    if(n==-1)
    {
        return NULL;
    }
    root=new TreeNode(n);
    cout<<"Enter the value of left node "<<n<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter the value of right node "<<n<<endl;
    root->right=buildtree(root->right);

}
int solve(TreeNode* root,int k,int &ans)
{
    
     if (root == NULL) {
        return -1;
    }
    
    if (root->val >= k) {
        ans = root->val;
        int leftceil = solve(root->left, k, ans);
        if (leftceil != -1) {
            ans = leftceil;
        }
    }
    else {
        solve(root->right, k, ans);
    }
    
    return ans;
}
 

int main()
{
    TreeNode* root=NULL;
   root=buildtree(root);
    int ans=-1;
    cout<<endl;
    cout<<"ceil of BST"<<endl;
    int input;
    cout<<"Enter the value "<<endl;
    cin>>input;
    cout<<endl;
    cout<<solve(root,input,ans);


}