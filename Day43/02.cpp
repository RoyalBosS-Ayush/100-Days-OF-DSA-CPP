#include <iostream>
#include <map>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
        nodeToIndex[in[i]] = i;
}

Node *solve(int in[], int post[], int n, int &index, int inOrderStart, int inOrderEnd, map<int, int> &nodeToIndex)
{
    if (index < 0 || inOrderStart > inOrderEnd)
        return NULL;

    int element = post[index--];
    Node *root = new Node(element);
    int position = nodeToIndex[element];

    root->right = solve(in, post, n, index, position + 1, inOrderEnd, nodeToIndex);
    root->left = solve(in, post, n, index, inOrderStart, position - 1, nodeToIndex);
    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);

    int preOrderIndex = n - 1;
    Node *ans = solve(in, post, n, preOrderIndex, 0, n - 1, nodeToIndex);
    return ans;
}

// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1/