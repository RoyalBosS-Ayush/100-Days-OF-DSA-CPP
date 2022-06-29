
class info
{
public:
    int mini;
    int maxi;
    int size;
    bool isBST;
};

info solve(TreeNode<int> *root, int &ans)
{
    if (root == NULL)
        return {INT_MAX, INT_MIN, 0, true};

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    currNode.isBST = (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini));

        if (currNode.isBST)
            ans = max(ans, currNode.size);

    return currNode;
}

int largestBST(TreeNode<int> *root)
{
    int maxSize = 0;
    solve(root, maxSize);
    return maxSize;
}