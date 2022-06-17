#include <iostream>
#include <utility>

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
    pair<bool, int> isBalancedFast(Node *root)
    {
        if (root == NULL)
        {
            pair<bool, int> ans = make_pair(true, 0);
            return ans;
        }

        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);

        bool leftBalanced = left.first;
        bool rightBalanced = right.first;

        bool balanced = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.first = leftBalanced && rightBalanced && balanced;
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

public:
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
};

// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1