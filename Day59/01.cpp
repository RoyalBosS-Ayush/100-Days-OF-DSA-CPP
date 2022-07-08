#include <iostream>

using namespace std;

class TrieNode
{
public:
    char data;
    bool isTerminal;
    TrieNode *children[26];

    TrieNode(char ch)
    {
        data = ch;
        isTerminal = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie
{

public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index])
            child = root->children[index];
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'a';

        if (root->children[index])
            return searchUtil(root->children[index], word.substr(1));

        return false;
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    bool prefixUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
            return true;

        int index = word[0] - 'a';

        if (root->children[index])
            return prefixUtil(root->children[index], word.substr(1));

        return false;
    }

    bool startsWith(string prefix)
    {
        return prefixUtil(root, prefix);
    }

    void removeUtil(TrieNode *&root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';

        if (root->children[index])
            removeUtil(root->children[index], word.substr(1));
    }

    void remove(string word)
    {
        removeUtil(root, word);
    }
};

int main()
{

    Trie *t = new Trie();
    t->insert("do");
    t->insert("done");
    t->insert("doing");

    cout << "do Present? " << t->search("do") << endl;
    cout << "don Present? " << t->search("don") << endl;
    cout << "done Present? " << t->search("done") << endl;

    t->remove("done");
    cout << "done Present? " << t->search("done") << endl;

    return 0;
}