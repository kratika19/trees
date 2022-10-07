#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter data : " << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter left child of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter right child of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void leftTraversal(vector<int> &trav, node *root)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    trav.push_back(root->data);
    if (root->left)
        leftTraversal(trav, root->left);
    else
        leftTraversal(trav, root->right);
}

void leavesTraverse(vector<int> &trav, node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        trav.push_back(root->data);
        return;
    }

    leavesTraverse(trav, root->left);
    leavesTraverse(trav, root->right);
}

void rightTraversal(vector<int> &trav, node *root)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        rightTraversal(trav, root->right);
    else
        rightTraversal(trav, root->left);

    trav.push_back(root->data);


}

vector<int> boundaryTraversal(node *root)
{
    vector<int> result;

    result.push_back(root->data);

    leftTraversal(result, root->left);
    leavesTraverse(result, root->left);
    leavesTraverse(result, root->right);
    rightTraversal(result, root->right);

    return result;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    cout << "Boundary Traversal : ";
    vector<int> a = boundaryTraversal(root);

    for (auto i : a)
        cout << i << " ";
    return 0;
}

// Sample Input : 1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1
// Sample Output : 1 2 3 6 8 10 11 9 7 4
