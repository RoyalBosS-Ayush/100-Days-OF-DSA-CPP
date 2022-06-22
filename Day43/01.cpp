#include <iostream>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
    void createMapping(int in[], map<int, int> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
            nodeToIndex[in[i]] = i;
    }

    Node *solve(int in[], int pre[], int n, int &index, int inOrderStart, int inOrderEnd, map<int, int> &nodeToIndex)
    {
        if (index >= n || inOrderStart > inOrderEnd)
            return NULL;

        int element = pre[index++];
        Node *root = new Node(element);
        int position = nodeToIndex[element];

        root->left = solve(in, pre, n, index, inOrderStart, position - 1, nodeToIndex);
        root->right = solve(in, pre, n, index, position + 1, inOrderEnd, nodeToIndex);
        return root;
    }

public:
    Node *buildTree(int in[], int pre[], int n)
    {
        map<int, int> nodeToIndex;
        createMapping(in, nodeToIndex, n);

        int preOrderIndex = 0;
        Node *ans = solve(in, pre, n, preOrderIndex, 0, n - 1, nodeToIndex);
        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/construct-tree-1/1/