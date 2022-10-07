// A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and the sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

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

pair<bool, int> sumTreeFast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = sumTreeFast(root->left);
    pair<bool, int> right = sumTreeFast(root->right);
    pair<bool, int> ans;

    bool cond = root->data == left.second + right.second;

    if (cond && left.first && right.first)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
        ans.first = false;

    return ans;
}

bool sumTree(node *root)
{
    return sumTreeFast(root).first;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    cout << endl
         << "Tree Sum: " << sumTree(root) << endl;
    return 0;
}

// Sample Input : 3 1 -1 -1 2 -1 -1
// Sample Output : 1
