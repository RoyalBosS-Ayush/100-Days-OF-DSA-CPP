void preorder(BinaryTreeNode<int> *root, int &count)
{
    if (root == NULL)
        return;

    if (!root->left && !root->right)
        count++;

    preorder(root->left, count);
    preorder(root->right, count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    int count = 0;
    preorder(root, count);
    return count;
}

// https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055