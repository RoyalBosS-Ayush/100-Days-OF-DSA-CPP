class Solution
{
    int countNodes(struct Node *root)
    {
        if (root == NULL)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isCBT(struct Node *root, int index, int cnt)
    {
        if (root == NULL)
            return true;

        if (index >= cnt)
            return false;

        else
        {
            bool left = isCBT(root->left, 2 * index + 1, cnt);
            bool right = isCBT(root->right, 2 * index + 2, cnt);
            return left && right;
        }
    }

    bool isMaxOrder(struct Node *root)
    {
        if (root->left == NULL && root->right == NULL)
            return true;

        if (root->right == NULL)
            return root->data > root->left->data;

        else
        {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);

            return left && right && (root->data > root->left->data && root->data > root->right->data);
        }
    }

public:
    bool isHeap(struct Node *tree)
    {
        int index = 0;
        int count = countNodes(tree);
        return isCBT(tree, index, count) && isMaxOrder(tree);
    }
};

// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1