#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class TrieNode{
    public:
    char ch;
    TrieNode* children[26];
    bool isend;
    vector<string>s;

    TrieNode(char ele)
    {
        this->ch=ele;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isend=false;

    }
};
TrieNode* root=new TrieNode('*');

void insert(string h)
{
    TrieNode* node=root;
    for(int i=0;i<h.size();i++)
    {
        if(node->children[h[i]-'a'])
        {
            node=node->children[h[i]-'a'];
              node->s.push_back(h);
        }
        else
        {
            node->children[h[i]-'a']=new TrieNode(h[i]);
             node=node->children[h[i]-'a'];
              node->s.push_back(h);
           
        }
    }
    node->isend=true;
    // node->s.push_back(h);
}
// void search(string h)
// {
//     TrieNode* node=root;
//     for(int i=0;i<h.size();i++)
//     {
//         if(node->children[h[i]-'a'])
//         {
//             node=node->children[h[i]-'a'];
//         }
//         else 
//         {
//             break;
//         }
//     }
//    if (node == NULL || !node->isend) {
//         cout << "No words found" << endl;
//         return;
//     }
//     for (const auto& word : node->s) {
//         cout << word << " ";
//     }
//     cout << endl;
// }
void search(TrieNode* root)
{
    TrieNode* node=root;
    char g;
    while(true)
    {
        cout<<"Enter a character";
        cin>>g;
        if(g=='*')
        {
            break;
        }
        if(node->children[g-'a']==NULL)
        {
            cout<<"NO MATCH"<<endl;
            break;
        }
        node=node->children[g-'a'];
        for(auto y:node->s)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"Enter the strings"<<endl;
    cout<<"How many"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string k;
        cin>>k;
        insert(k);
    }
    search(root);
    
    // cout<<"How was it,rate it(out of 5)"<<endl;
    // int w;
    // cin>>w;
    // if(w<=3)
    // {
    //     cout<<"OK:(";
    // }
    // else{
    //     cout<<"WAAH WAAH"<<endl;
    // }
}