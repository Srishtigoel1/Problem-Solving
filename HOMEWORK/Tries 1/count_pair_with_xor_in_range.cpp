class TrieNode{
 public:
     TrieNode* children[2];
     int count;
     TrieNode()
     {
        children[0]=NULL;
        children[1]=NULL;
        count=0;
     }
};

class Trie{
    TrieNode* root;
 public:
  Trie()
  {
    root=new TrieNode;
  }

  void insert(int n)
  {
    TrieNode* node=root;
    for(int i=31;i>=0;i--)
    {
        int b=(n>>i)&1;
        if(node->children[b]==NULL)
          node->children[b]=new TrieNode();
        node=node->children[b];
        node->count++;
    }
  }

  int solve(int n,int high)
  {
    TrieNode* node=root;
    int c=0;
    for(int i=31;i>=0 && node!=NULL;i--)
    {
        int p=(n>>i)&1;
        int k=(high>>i)&1;
        if(k==1)
        {
            if(node->children[p]!=NULL)
              c+=node->children[p]->count;
            node=node->children[1-p];
        }
        else
            node=node->children[p];
    }
    return c;
  }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
       Trie trie;
       int c=0;
       for(int i=0;i<nums.size();i++)
       {
        c=c+trie.solve(nums[i],high+1)-trie.solve(nums[i],low);
        trie.insert(nums[i]);
       } 
       return c;
    }
};
