void inOrderTraversal(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left, in);
    in.push_back(root->data);
    inOrderTraversal(root->right, in);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> inorder;
    inOrderTraversal(root, inorder);
    int size = inorder.size();

    TreeNode<int> *newRoot = new TreeNode<int>(inorder[0]);
    TreeNode<int> *curr = newRoot;

    for (int i = 1; i < size; i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(inorder[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    return newRoot;
}

// https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=3