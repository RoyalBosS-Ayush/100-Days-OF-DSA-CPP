BinaryTreeNode<int> *solve(vector<int> &preorder, int &index, int mini, int maxi)
{
    if (index >= preorder.size())
        return NULL;

    if (preorder[index] < mini || preorder[index] > maxi)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[index++]);
    root->left = solve(preorder, index, mini, root->data);
    root->right = solve(preorder, index, root->data, maxi);
    return root;
}

BinaryTreeNode<int> *preorderToBST(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int index = 0;
    BinaryTreeNode<int> *newRoot = solve(preorder, index, mini, maxi);
    return newRoot;
}

// https://www.codingninjas.com/codestudio/problems/preorder-traversal-to-bst_893111?leftPanelTab=1