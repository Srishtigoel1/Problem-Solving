class TrieNode{
    public:
    TrieNode* children[26];
    bool isend;

    TrieNode()
    {
       
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isend=false;
    }
};
class Trie {
public:
TrieNode* root;
    Trie() {

         root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->children[word[i]-'a']==NULL)//not present
            {
                    node->children[word[i]-'a']=new TrieNode();
            }
            else
            {
                //present
            }
            node=node->children[word[i]-'a'];
        }
        node->isend=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->children[word[i]-'a'])
            {
                node=node->children[word[i]-'a'];
            }
            else
            {
                return false;
            }
        }
        return node!=NULL && node->isend==true;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        bool flag=false;
        for(int i=0;i<prefix.size();i++)
        {
            if(node==NULL || node->children[prefix[i]-'a']==NULL)
            {
                return false;
            }node=node->children[prefix[i]-'a'];
        }
       
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */