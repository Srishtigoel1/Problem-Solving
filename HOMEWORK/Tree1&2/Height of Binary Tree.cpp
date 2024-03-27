/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int heightOfBinaryTree(TreeNode<int> *root)
{
	if(root==nullptr)
    {
        return 0;
    }
    int sub1=heightOfBinaryTree(root->left);
    int sub2=heightOfBinaryTree(root->right);
    return max(sub1,sub2)+1;
}