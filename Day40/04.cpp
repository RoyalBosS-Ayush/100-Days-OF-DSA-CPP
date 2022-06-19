#include <iostream>
#include <vector>

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
    void solve(Node *root, vector<int> &ans, int lvl)
    {
        if (root == NULL)
            return;

        if (ans.size() == lvl)
            ans.push_back(root->data);

        solve(root->right, ans, lvl + 1);
        solve(root->left, ans, lvl + 1);
    }

public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1/