class Solution
{
    Node *createMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
    {
        Node *res = NULL;
        nodeToParent[root] = NULL;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            if (front->left)
            {
                q.push(front->left);
                nodeToParent[front->left] = front;
            }
            if (front->right)
            {
                q.push(front->right);
                nodeToParent[front->right] = front;
            }
            if (front->data == target)
            {
                res = front;
            }
        }
        return res;
    }

    int burn(Node *root, map<Node *, Node *> nodeToParent)
    {
        map<Node *, bool> visited;
        queue<Node *> q;

        q.push(root);
        int ans = 0;

        while (!q.empty())
        {
            int size = q.size();
            bool flag = 0;
            for (int i = 0; i < size; i++)
            {
                Node *front = q.front();
                q.pop();
                if (front->left && !visited[front->left])
                {
                    q.push(front->left);
                    visited[front->left] = 1;
                    flag = 1;
                }
                if (front->right && !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right] = 1;
                    flag = 1;
                }
                if (nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                    flag = 1;
                }
            }
            if (flag)
                ans++;
        }
        return ans;
    }

public:
    int minTime(Node *root, int target)
    {
        map<Node *, Node *> nodeToParent;
        Node *targetNode = createMapping(root, target, nodeToParent);
        int ans = burn(targetNode, nodeToParent);
        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/burning-tree/1