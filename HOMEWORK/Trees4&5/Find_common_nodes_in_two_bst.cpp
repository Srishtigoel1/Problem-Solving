class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    void inorder(Node* root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        //lNR
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     vector<int>a;
     vector<int>b;
     inorder(root1,a);
     inorder(root2,b);
     unordered_map<int,int>m;
     for(int i=0;i<a.size();i++)
     {
         m[a[i]]++;
     }
     a.clear();
     for(int i=0;i<b.size();i++)
     {
         if(m.find(b[i])!=m.end())
         {
             //mila 
             a.push_back(b[i]);
             
         }
         
     }
     return a;
    }
};
