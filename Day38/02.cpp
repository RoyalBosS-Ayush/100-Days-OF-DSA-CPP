#include <iostream>
#include <utility>

using namespace std;

pair<int, int> diameterFast(struct Node *root)
{
    if (root == NULL)
    {
        pair<int, int> ans = make_pair(0, 0);
        return ans;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(struct Node *root)
{
    return diameterFast(root).first;
}

// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1