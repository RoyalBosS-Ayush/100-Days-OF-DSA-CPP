class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        map<int, map<int, vector<int>>> nodes;
        queue<pair<Node *, pair<int, int>>> q;

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            pair<Node *, pair<int, int>> temp = q.front();
            q.pop();

            Node *front = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(front->data);

            if (front->left)
                q.push(make_pair(front->left, make_pair(hd - 1, lvl + 1)));
            if (front->right)
                q.push(make_pair(front->right, make_pair(hd + 1, lvl + 1)));
        }

        for (auto i : nodes)
        {
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1