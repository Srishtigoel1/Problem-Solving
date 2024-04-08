//FIRST APPROACH

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
void inorder(TreeNode* root,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
void correct(TreeNode* root,vector<int>&ans,int &i)
{
    if(root==NULL)
    {
        return ;
    }
    correct(root->left,ans,i);
    root->val=ans[i++];
    correct(root->right,ans,i);
}
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        sort(ans.begin(),ans.end());
        int i=0;
        correct(root,ans,i);
        
    }
};


//SECOND APPROACH

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
 void inorderTraversal(TreeNode* node, vector<TreeNode*>& nodes) {
    if (!node) return;
    inorderTraversal(node->left, nodes);
    nodes.push_back(node);
    inorderTraversal(node->right, nodes);
}

void recoverTree(TreeNode* root) {
    vector<TreeNode*> nodes;
    inorderTraversal(root, nodes);
    TreeNode* first = nullptr, *second = nullptr;
    for (int i = 0; i < nodes.size() - 1; i++) {
        if (nodes[i]->val > nodes[i + 1]->val) {
            first = nodes[i];
            break;
        }
    }
    for (int i = nodes.size() - 1; i >= 0; i--) {
        if (!first) break;
        if (nodes[i]->val < first->val) {
            second = nodes[i];
            break;
        }
    }
    if (first && second) swap(first->val, second->val);
}
};
