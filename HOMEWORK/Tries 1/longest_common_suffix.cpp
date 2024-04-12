class Solution {
public:
    class TrieNode {
    public:
        TrieNode* children[26];
        int len;
        int ans;

        TrieNode() {
            for(int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            ans = INT_MAX;
            len = INT_MAX;
        }
    };

    void insertstring(TrieNode* root, string s, int i) {
        int len = s.size();
        TrieNode* node = root;
        if (len < node->len) {
            node->len = len;
            node->ans = i;
        }
        reverse(s.begin(), s.end());
        for (int j = 0; j < len; j++) {
            int idx = s[j] - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];

            if (len < node->len) {
                node->len = len;
                node->ans = i;
            }
        }

        if (len < node->len) {
            node->len = len;
            node->ans = i;
        }
    }

    int searchstring(TrieNode* root, string s) {
        reverse(s.begin(), s.end());
        TrieNode* node = root;
        int len = s.size();
        for (int j = 0; j < len; j++) {
            int idx = s[j] - 'a';
            if (!node->children[idx]) break;
            node = node->children[idx];
        }
        return node->ans;
    }

    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        int n = wc.size();
        TrieNode* root = new TrieNode();
        for (int i = 0; i < n; i++) insertstring(root, wc[i], i);
        n = wq.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) ans.push_back(searchstring(root, wq[i]));
        return ans;
    }
};

