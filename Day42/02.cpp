#include <iostream>
#include <utility>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return the maximum sum of non-adjacent nodes.
    //  <included, excluded>
    pair<int, int> solve(Node *root)
    {
        if (root == NULL)
            return make_pair(0, 0);

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        pair<int, int> p;

        p.first = root->data + left.second + right.second;
        p.second = max(left.first, left.second) + max(right.first, right.second);

        return p;
    }

    int getMaxSum(Node *root)
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};

// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/