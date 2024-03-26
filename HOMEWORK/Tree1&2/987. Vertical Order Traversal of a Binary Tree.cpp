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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> m;
        //structure:-x-axis,nodes value
        queue<pair<TreeNode*,pair<int,int>>>q;
        //structur:-node,x-axis,y-axis
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto n=q.front();
            auto x=n.second.first;//x axis
            auto y=n.second.second;//y axis
            q.pop();
            m[x][y].push_back(n.first->val);
            if(n.first->left!=NULL)
            {
                //left->x-1;
                q.push({n.first->left,{x-1,y+1}});
            }
              if(n.first->right!=NULL)
            {
                //left->x-1;
                q.push({n.first->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>ans;
      
for (auto& col : m) {
    vector<int> nodes;
    for (auto& row : col.second) {
        sort(row.second.begin(), row.second.end());
                nodes.insert(nodes.end(), row.second.begin(), row.second.end());
        }
    
    ans.push_back(nodes);
}
        return ans;
        
    }
};