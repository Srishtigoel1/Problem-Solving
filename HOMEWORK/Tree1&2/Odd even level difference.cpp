class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
      
       //first level is odd level
       //i will traverse level wise and then calculate acc to level is odd or even
       queue<Node*>q;
       q.push(root);
       int esum=0;
       int osum=0;
       int level=1;
       while(!q.empty())
       {
           int size=q.size();
           if(level%2!=0){
           for(int i=0;i<size;i++)
           {
               auto x=q.front();
               osum=osum+x->data;
               q.pop();
               if(x->left!=NULL)
               {
                   q.push(x->left);
               }
               if(x->right!=NULL)
               {
                   q.push(x->right);
               }
           }
           }
           else
           {
               for(int i=0;i<size;i++)
           {
               auto x=q.front();
               esum=esum+x->data;
               q.pop();
               if(x->left!=NULL)
               {
                   q.push(x->left);
               }
               if(x->right!=NULL)
               {
                   q.push(x->right);
               }
           }
           }
           level++;
       }
       return osum-esum;
    }
};
