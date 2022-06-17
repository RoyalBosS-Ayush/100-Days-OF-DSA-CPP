int height(struct Node *node)
{
    if (node == NULL)
        return 0;

    int left = height(node->left);
    int right = height(node->right);

    int max = left > right ? left : right;
    return max + 1;
}

// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1