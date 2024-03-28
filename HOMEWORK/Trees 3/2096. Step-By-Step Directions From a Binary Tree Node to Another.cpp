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
bool dfs(string &s,TreeNode* root,int value)
{
    //path from root to node 
    if(root==NULL)
    {
        return false;
    }
    if(root->val==value)
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
    string getDirections(TreeNode* root, int startValue, int destValue) {
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
        return st+d;
        
    }
};