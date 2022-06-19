#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        map<int, int> topNode;
        queue<pair<Node *, int>> q;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();
            Node *front = temp.first;
            int hd = temp.second;

            topNode[hd] = front->data;

            if (front->left)
                q.push(make_pair(front->left, hd - 1));
            if (front->right)
                q.push(make_pair(front->right, hd + 1));
        }

        for (auto i : topNode)
            ans.push_back(i.second);

        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1/