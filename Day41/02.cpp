#include <iostream>

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

class Solution
{
public:
    Node *lca(Node *root, int n1, int n2)
    {
        if (root == NULL)
            return NULL;

        if (root->data == n1 || root->data == n2)
            return root;

        Node *leftAns = lca(root->left, n1, n2);
        Node *rightAns = lca(root->right, n1, n2);

        if (leftAns != NULL && rightAns != NULL)
            return root;

        if (leftAns == NULL && rightAns != NULL)
            return rightAns;
        if (leftAns != NULL && rightAns == NULL)
            return leftAns;

        return NULL;
    }
};

// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1