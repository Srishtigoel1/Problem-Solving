class TrieNode{
    public:
   
    TrieNode* children[26];
    bool isend;
    string word;
    TrieNode()
    {
        
        for(int i=0;i<26;i++)
        {
            children[i]= NULL;
        }
        isend=false;
        string word="";
    }
};

//    void insert(string &s)
// {
//     TrieNode* node=root;
//     for(int i=0;i<s.size();i++)
//     {
//         if(node->children[s[i]-'a']==NULL)
//         {
//             node->children[s[i]-'a']=new TrieNode();
//         }
//         node=node->children[s[i]-'a'];
//     }
//     node->isend=true;
//     node->word=s;
// }
// string search(string sentence)
// {
//     TrieNode* node=root;
//     for(int i=0;i<sentence.size();i++)
//     {
//         if(node->isend)
//         {
//             return node->word;
//         }
//         if(node->children[sentence[i]-'a']==NULL)
//         {
//             return sentence;
//         }
       
//           node=node->children[sentence[i]-'a'];
        
//     }
//    return sentence;
// }

class Solution {
public:
    TrieNode* root=new TrieNode();
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(int i=0;i<dictionary.size();i++)
        {
            insert(dictionary[i]);
        }
        stringstream ss(sentence);//the sentence will be breaked into words
        string ans;
        while(ss>>sentence)
        {
            ans+=(search(sentence));
            ans+=" ";
        }
        if(!ans.empty())
        {
            ans.pop_back();
        }
        return ans;
        
    }
    void insert(string &s)
{
    TrieNode* node=root;
    for(int i=0;i<s.size();i++)
    {
        if(node->children[s[i]-'a']==NULL)
        {
            node->children[s[i]-'a']=new TrieNode();
        }
        node=node->children[s[i]-'a'];
    }
    node->isend=true;
    node->word=s;
}
string search(string sentence)
{
    TrieNode* node=root;
    for(int i=0;i<sentence.size();i++)
    {
        if(node->isend)
        {
            return node->word;
        }
        if(node->children[sentence[i]-'a']==NULL)
        {
            return sentence;
        }
       
          node=node->children[sentence[i]-'a'];
        
    }
   return sentence;
}
//why it is not running when above class solution but running under class solution?

 
};