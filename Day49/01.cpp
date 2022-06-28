void inorder(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeSortedArrays(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
            ans[k++] = a[i++];
        else
            ans[k++] = b[j++];
    }

    while (i < a.size())
        ans[k++] = a[i++];

    while (j < b.size())
        ans[k++] = b[j++];

    return ans;
}

TreeNode<int> *inorderToBST(vector<int> &in, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;

    TreeNode<int> *root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(in, s, mid - 1);
    root->right = inorderToBST(in, mid + 1, e);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    vector<int> mergedArray = mergeSortedArrays(bst1, bst2);

    int s = 0, e = mergedArray.size() - 1;
    TreeNode<int> *root = inorderToBST(mergedArray, s, e);

    return root;
}

// https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar