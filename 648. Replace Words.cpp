class TrieNode {

  public:
    char ch;
    bool isend;
    vector<TrieNode *> children;

    TrieNode() : ch(' '), isend(false) {}
    TrieNode(char x) : ch(x), isend(false) {}
    TrieNode *findchild(char x) {
        for(auto c : children) {
            if(c->ch == x)
                return c;
        }
        return nullptr;
    }
};

class Trie {
    TrieNode *root;

  public:
    Trie() {
        root = new TrieNode();
    }

    void addwords(string word) {
        TrieNode *cur = root;
        for(auto c : word) {
            TrieNode *ifchild = cur->findchild(c);
            if(ifchild == nullptr) {
                ifchild = new TrieNode(c);
                cur->children.push_back(ifchild);
            }
            cur = ifchild;
        }
        cur->isend = true;
    }

    string prefixexists(string word) {
        TrieNode *cur = root;
        string prefix = "";
        for(auto c : word) {

            if(cur->isend) {
                return prefix;
            }

            TrieNode *ifchild = cur->findchild(c);

            if(ifchild == nullptr) {
               return "";
            }

            cur = ifchild;
            prefix += cur->ch;
        }
        if(cur->isend)
            return prefix;
        else
            return "";
    }
};

class Solution {

public:
    string replaceWords(vector<string>& dict, string sentence) {

        if(dict.empty() || sentence.empty())
            return sentence;

        Trie *t = new Trie();

        for(auto words : dict) {
            t->addwords(words);
        }

        stringstream iss(sentence);
        string word;
        string newsentence = "";

        while(iss >> word) {
            string newword = t->prefixexists(word);
            if(!newword.empty())
                newsentence += newword;
            else
                newsentence += word;

            newsentence += " ";
        }
        newsentence.pop_back(); //delete last space in the string. Works in C++11
        return newsentence;
    }
};
