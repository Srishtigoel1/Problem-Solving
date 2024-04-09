class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node* head=NULL;
    Node* prev=NULL;
    Node *bTreeToCList(Node *root)
    {
        solve(root);
        head->left=prev;
        prev->right=head;
        return head;
    }
    void solve(Node* curr)
    {
        if(curr==NULL)
        {
            return;
        }
        solve(curr->left);
        if(head==NULL)
        {
            head=prev=curr;
        }
        else
        {
            prev->right=curr;
            curr->left=prev;
        }
        prev=curr;
        solve(curr->right);
    }
};