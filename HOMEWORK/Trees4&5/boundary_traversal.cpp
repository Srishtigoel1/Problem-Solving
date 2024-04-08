/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
template <typename T>
bool isleaf(TreeNode<T>* node) {
    return (node && !node->left && !node->right);
}

template <typename T>
void leftboundary(TreeNode<T>* root, vector<T>& ans) {
    TreeNode<T>* cur = root->left;
    while (cur) {
        if (!isleaf(cur)) {
            ans.push_back(cur->data);
        }
        if (cur->left) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
}

template <typename T>
void rightboundary(TreeNode<T>* root, vector<T>& ans) {
    TreeNode<T>* cur = root->right;
    vector<T> t;
    while (cur) {
        if (!isleaf(cur)) {
            t.push_back(cur->data);
        }
        if (cur->right) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    for (int i = t.size() - 1; i >= 0; i--) {
        ans.push_back(t[i]);
    }
}

template <typename T>
void leaves(TreeNode<T>* root,   vector<T>& ans) {
    if (isleaf(root)) {
        ans.push_back(root->data);
        return;
    }
    if (root->left) {
        leaves(root->left, ans);
    }
    if (root->right) {
        leaves(root->right, ans);
    }
}

template <typename T>
vector<T> traverseBoundary(TreeNode<T>* root) {
    vector<T> ans;
    if (!root) {
        return ans;
    }
    if (!isleaf(root)) {
        ans.push_back(root->data);
    }
    leftboundary(root, ans);
    leaves(root, ans);
    rightboundary(root, ans);
    return ans;
}
