struct TrieNode {
    TrieNode *children[26] = {};
    int cnt = 0;
};

class Solution {
    TrieNode root;
public:
    void insert(string word) {
        TrieNode* node = &root;
        for(char ch : word) {
            if(!node->children[ch - 'a']) {
                node->children[ch - 'a'] = new TrieNode();
                //if null create one 
            } 
            node->children[ch - 'a']->cnt++;
            //increment the counter
            node = node->children[ch - 'a'];   
            //move forward
        }
    }

    int search(string s) {
        TrieNode* node = &root;
        int ans = 0;
        for(char ch : s) {
            ans += node->children[ch - 'a']->cnt;
            node = node->children[ch - 'a'];
        }
        return ans;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
                insert(words[i]);
        }
        vector<int> ans(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            ans[i] = search(words[i]); 
        }
        return ans;
    }
};