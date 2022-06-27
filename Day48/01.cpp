void inOrderTraversal(BinaryTreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left, in);
    in.push_back(root->data);
    inOrderTraversal(root->right, in);
}

bool twoSumInBST(BinaryTreeNode<int> *root, int target)
{
    vector<int> inorder;
    inOrderTraversal(root, inorder);

    int s = 0, e = inorder.size() - 1;
    while (s < e)
    {
        int sum = inorder[s] + inorder[e];
        if (sum == target)
            return true;
        if (sum > target)
            e--;
        else
            s++;
    }
    return false;
}

// https://www.codingninjas.com/codestudio/problems/two-sum-in-a-bst_1062631?leftPanelTab=1