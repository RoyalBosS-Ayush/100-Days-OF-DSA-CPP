#include <iostream>
#include <utility>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    pair<bool, int> isSumTreeFast(Node *root)
    {
        if (root == NULL)
        {
            pair<bool, int> ans = make_pair(true, 0);
            return ans;
        }

        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> ans = make_pair(true, root->data);
            return ans;
        }

        pair<bool, int> left = isSumTreeFast(root->left);
        pair<bool, int> right = isSumTreeFast(root->right);

        bool isleftSumTree = left.first;
        bool isrightSumTree = right.first;

        bool cond = root->data == (left.second + right.second);

        pair<bool, int> ans;
        ans.first = isleftSumTree && isrightSumTree && cond;
        ans.second = 2 * root->data;

        return ans;
    }
    bool isSumTree(Node *root)
    {
        return isSumTreeFast(root).first;
    }
};

// https://practice.geeksforgeeks.org/problems/sum-tree/1