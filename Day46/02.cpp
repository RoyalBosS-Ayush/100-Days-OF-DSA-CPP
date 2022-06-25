// bool searchInBST(BinaryTreeNode<int> *root, int x)
// {
//     if (root == NULL)
//         return false;

//     if (root->data == x)
//         return true;

//     if (root->data < x)
//         return searchInBST(root->right, x);

//     if (root->data > x)
//         return searchInBST(root->left, x);
// }

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *curr = root;
    while (curr != NULL){
        if (curr->data == x)
            return true;

        if (curr->data < x)
            curr = curr->right;
        else
            curr = curr->left;
    }
    
    return false;
}

// https://www.codingninjas.com/codestudio/problems/search-in-bst_1402878?leftPanelTab=1