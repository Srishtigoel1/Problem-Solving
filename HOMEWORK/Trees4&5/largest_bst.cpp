class NodeInfo{
    public:
int maxnode,minnode,maxsize;
    NodeInfo(int minnode,int maxnode,int maxsize)
    {
        this->maxnode=maxnode;
        this->minnode=minnode;
        this->maxsize=maxsize;
    }
Class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
//constructor
        data = val;
        left = right = NULL;
    }
};
class Solution{
    private:
    NodeInfo solve(Node* root)
    {
        if(root==false)
        {
            return NodeInfo(INT_MAX,INT_MIN,0);
        }
        auto left=solve(root->left);
        auto right=solve(root->right);
        if(left.maxnode < root->data && root->data <right.minnode)
        {
            //mean ki if largest from left subtree < root < smallest in right subtree
            return NodeInfo(min(root->data,left.minnode),max(root->data,right.maxnode),left.maxsize+right.maxsize+1);

        }
        return NodeInfo(INT_MIN,INT_MAX,max(left.maxsize,right.maxsize));
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	return solve(root).maxsize;
    }
};