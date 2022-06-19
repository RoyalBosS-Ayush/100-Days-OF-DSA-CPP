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

void solve(Node *root, vector<int> &ans, int lvl)
{
    if (root == NULL)
        return;

    if (ans.size() == lvl)
        ans.push_back(root->data);

    solve(root->left, ans, lvl + 1);
    solve(root->right, ans, lvl + 1);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}