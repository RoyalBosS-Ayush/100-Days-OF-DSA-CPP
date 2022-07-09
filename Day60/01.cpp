#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans;
    for (int j = 0; j < arr[0].length(); j++)
    {
        char ch = arr[0][j];
        bool match = true;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i][j] != ch)
                return ans;
        }
        ans.push_back(ch);
    }
    return ans;
}

// class TrieNode
// {
// public:
//     char ch;
//     TrieNode *children[26];
//     int childCount;
//     bool isTerminal;

//     TrieNode(char ch)
//     {
//         this->ch = ch;
//         childCount = 0;
//         isTerminal = false;

//         for (int i = 0; i < 26; i++)
//         {
//             children[i] = NULL;
//         }
//     }
// };

// class Trie
// {
// public:
//     TrieNode *root;

//     Trie(char ch)
//     {
//         root = new TrieNode(ch);
//     }

//     void insertUtil(TrieNode *root, string word)
//     {
//         if (word.length() == 0)
//         {
//             root->isTerminal = true;
//             return;
//         }

//         int index = word[0] - 'a';
//         TrieNode *child;

//         if (root->children[index])
//         {
//             child = root->children[index];
//         }
//         else
//         {
//             child = new TrieNode(word[0]);
//             root->childCount++;
//             root->children[index] = child;
//         }

//         insertUtil(child, word.substr(1));
//     }

//     void insert(string word)
//     {
//         insertUtil(root, word);
//     }

//     string lcp(string str)
//     {
//         string ans;
//         for (int i = 0; i < str.length(); i++)
//         {
//             char ch = str[i];

//             if (root->childCount == 1)
//             {
//                 ans.push_back(ch);
//                 root = root->children[ch - 'a'];
//             }
//             else
//             {
//                 break;
//             }
//             if (root->isTerminal)
//                 break;
//         }
//         return ans;
//     }
// };

// string longestCommonPrefix(vector<string> &arr, int n)
// {
//     Trie *t = new Trie('\0');
//     for (int i = 0; i < arr.size(); i++)
//     {
//         t->insert(arr[i]);
//     }

//     return t->lcp(arr[0]);
// }

// https: // www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383