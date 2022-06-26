pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    BinaryTreeNode<int> *temp = root;
    int pred = -1;
    int succ = -1;

    while (temp->data != key)
    {
        if (temp->data > key)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    BinaryTreeNode<int> *left = temp->left;
    while (left != NULL)
    {
        pred = left->data;
        left = left->right;
    }

    BinaryTreeNode<int> *right = temp->right;
    while (right != NULL)
    {
        succ = right->data;
        right = right->left;
    }

    return make_pair(pred, succ);
}

// https://www.codingninjas.com/codestudio/problems/_893049