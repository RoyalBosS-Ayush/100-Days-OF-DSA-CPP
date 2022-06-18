#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> result;

        if (root == NULL)
            return result;

        queue<Node *> q;
        q.push(root);
        bool l2r = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);

            for (int i = 0; i < size; i++)
            {
                Node *front = q.front();
                q.pop();

                int index = l2r ? i : size - i - 1;
                ans[index] = front->data;

                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
            }
            l2r = !l2r;
            for (int i : ans)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

// https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1/