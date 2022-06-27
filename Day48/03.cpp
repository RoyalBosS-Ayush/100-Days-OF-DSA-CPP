void inOrderTraversal(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left, in);
    in.push_back(root->data);
    inOrderTraversal(root->right, in);
}

TreeNode<int> *inorderToBST(int s, int e, vector<int> &in)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    TreeNode<int> *root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);
    return root;
}

TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    vector<int> inorder;
    inOrderTraversal(root, inorder);
    int size = inorder.size();

    TreeNode<int> *newRoot = inorderToBST(0, size - 1, inorder);
    return newRoot;
}

// https://www.codingninjas.com/codestudio/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=1