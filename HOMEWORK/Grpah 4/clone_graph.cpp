/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
//using recursion
Node* help(Node* node,unordered_map<Node*,Node*>& mp)
{
    Node* m=new Node(node->val);
    mp[node]=m;
    for(auto i:node->neighbors)
    {
        if(mp.find(i)==mp.end())//nhi mila
        {
            //create
            (m->neighbors).push_back(help(i,mp));//then call dfs
        }
        else
        {
            (m->neighbors).push_back(mp[i]);
        }
    }
    return m;
}
    Node* cloneGraph(Node* node) {
        if(!node)
        return NULL;

        unordered_map<Node*,Node*>mp;
        return help(node,mp);
        
    }
};