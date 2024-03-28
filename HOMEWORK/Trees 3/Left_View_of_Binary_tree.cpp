vector<int> printLeftView(BinaryTreeNode<int>* root) {
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    vector<int>a;
    while(!q.empty())
    {
      
        vector<int>ans;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
              auto x=q.front();
                q.pop();
                ans.push_back(x->data);
                if(x->left)
                {
                    q.push(x->left);
                }
                if(x->right)
                {
                    q.push(x->right);
                }
        }
        a.push_back(ans[0]);

    }
    return a;
}