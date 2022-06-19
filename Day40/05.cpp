#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void solve(Node *root, map<int, vector<int>> &ans, int hd, int lvl)
{
    if (root == NULL)
        return;

    ans[(lvl - hd) / 2].push_back(root->data);

    solve(root->left, ans, hd - 1, lvl + 1);
    solve(root->right, ans, hd + 1, lvl + 1);
}

vector<int> diagonal(Node *root)
{
    vector<int> result;
    map<int, vector<int>> ans;

    if (root == NULL)
        return result;

    solve(root, ans, 0, 0);

    for (auto i : ans)
    {
        for (auto j : i.second)
        {
            result.push_back(j);
        }
    }
    return result;
}

// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1/