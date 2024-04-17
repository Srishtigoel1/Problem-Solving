struct TrieNode {
    TrieNode* children[2];
    
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }

    bool hasChild(int b) {
        return children[b] != nullptr;
    }

    TrieNode* getChild(int b) {
        return children[b];
    }

    void setChild(int b, TrieNode* node) {
        children[b] = node;
    }
};
class Trie
{
    private:
     TrieNode* root;
     public:
     Trie(){
        root=new TrieNode();
     }
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int b = (num >> i) & 1;
            if (!node->hasChild(b))
                node->setChild(b, new TrieNode());
            node = node->getChild(b);
        }
    }

    int getMax(int num) {
        TrieNode* node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--) {
            int b = (num >> i) & 1;
            if (node->hasChild(1 - b)) {
                maxi |= (1 << i);
                node = node->getChild(1 - b);
            } else {
                node = node->getChild(b);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (auto&i: nums)
            trie.insert(i);

        int maxi = 0;
        for (auto&i : nums)
            maxi = max(maxi, trie.getMax(i));

        return maxi;
    }
};
