
class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    bool dfs(string &s,Node* root,int value)
{
    //path from root to node 
    if(root==NULL)
    {
        return false;
    }
    if(root->data==value)
    {
        return true;
    }
    
        // bool left=dfs(s,root->left,value);
        if(dfs(s,root->left,value))
        {
            s+='L';//why s=s+'L' gives memory limit exceeded? and not this 
            return true;
        }
    
    
        //  bool right=dfs(s,root->right,value);
        if(dfs(s,root->right,value))
        {
            s+='R';
            return true;
        }
    
    return false;
}
    int getDirections(Node* root, int startValue, int destValue) {
        string st="";
        string d="";
        dfs(st,root,startValue);
        dfs(d,root,destValue);
        int i=st.size()-1;
        int j=d.size()-1;
        while(i>=0 && j>=0 && st[i]==d[j])
        {
            st.pop_back();
            d.pop_back();
            i--;
            j--;
        }
        i=st.size();
        for(int j=0;j<i;j++)
        {
            st[j]='U';
        }
        reverse(d.begin(),d.end());
       string h= st+d;
       return h.size();
        
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        return getDirections(root,a,b);
    }
};