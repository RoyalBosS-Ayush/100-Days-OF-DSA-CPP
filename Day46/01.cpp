#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

Node *insertIntoBst(Node *root, int data)
{
    if (root == NULL)
        return new Node(data);

    if (data < root->data)
        root->left = insertIntoBst(root->left, data);
    else
        root->right = insertIntoBst(root->right, data);

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cout << "Enter data to create bst: ";
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

int min(Node *root)
{
    Node *curr = root;
    while (curr->left != NULL)
        curr = curr->left;

    return curr->data;
}

int max(Node *root)
{
    Node *curr = root;
    while (curr->right != NULL)
        curr = curr->right;

    return curr->data;
}

Node *deleteFromBst(Node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->data == val)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->left != NULL && root->right != NULL)
        {
            int mini = min(root->right);
            root->data = mini;
            root->right = deleteFromBst(root->right, mini);
        }
    }
    else if (root->data > val)
        root->left = deleteFromBst(root->left, val);
    else if (root->data < val)
        root->right = deleteFromBst(root->right, val);

    return root;
}

int main()
{
    Node *root = NULL;

    takeInput(root);
    // 10 8 21 7 27 5 4 3 -1
    // 50 20 70 10 30 90 110 -1

    levelOrderTraversal(root);

    cout << "Min: " << min(root) << endl;
    cout << "Max: " << max(root) << endl;

    deleteFromBst(root, 50);
    levelOrderTraversal(root);

    return 0;
}