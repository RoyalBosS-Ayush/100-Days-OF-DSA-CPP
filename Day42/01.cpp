#include <iostream>

using namespace std;

Node *solve(Node *root, int &k, int node)
{
    if (root == NULL)
        return NULL;

    if (root->data == node)
        return root;

    Node *lNode = solve(root->left, k, node);
    Node *rNode = solve(root->right, k, node);

    if (lNode || rNode)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX; // lock root (above condition will never be fulfilled)
            return root;
        }
        return lNode ? lNode : rNode;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
    return ans->data;
}

// https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1/