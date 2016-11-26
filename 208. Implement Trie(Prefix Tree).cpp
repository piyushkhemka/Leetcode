class TrieNode {

public:
    char ch;
    bool isend;
    vector<TrieNode *> children;
    // Initialize your data structure here.
    TrieNode(): ch(' '),isend(false) {};
    TrieNode(char c) : ch(c), isend(false) {};

    TrieNode *fchild(char c) {
        if (!children.empty()) {
            for(auto child: children) {
                if(child->ch == c)
                    return child;
            }
        }
        return NULL;
    }

    ~TrieNode() {
            for (auto child : children)
                delete child;
        }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {

        if(search(word))
            return;

        TrieNode *cur = root;
        for(auto c : word) {

            TrieNode *child = cur->fchild(c);
            if(child)
                cur = child;
            else {
                child = new TrieNode (c);
                cur->children.push_back(child);
                cur = child;
            }
        }

        cur->isend = true;

    }

    // Returns if the word is in the trie.
    bool search(string word) {

        TrieNode *cur = root;

        for(auto c : word) {
            TrieNode *child = cur->fchild(c);
            if (child)
                cur = child;
            else
                return false;
        }

        return cur->isend == true;

    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {

        TrieNode *cur = root;

        for(auto c : prefix) {
            TrieNode *child = cur->fchild(c);
            if (child)
                cur = child;
            else
                return false;
        }

        return true;

    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
