// TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *P, TreeNode<int> *Q)
// {
//     if (root->data > P->data && root->data > Q->data)
//         return LCAinaBST(root->left, P, Q);

//     if (root->data < P->data && root->data < Q->data)
//         return LCAinaBST(root->right, P, Q);

//     return root;
// }

TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *P, TreeNode<int> *Q)
{
    TreeNode<int> *temp = root;
    while (temp != NULL)
    {
        if (temp->data > P->data && temp->data > Q->data)
            temp = temp->left;
        else if (temp->data < P->data && temp->data < Q->data)
            temp = temp->right;
        else
            return temp;
    }
}

// https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280?leftPanelTab=1