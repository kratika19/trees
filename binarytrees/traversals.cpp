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

void inOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(node* root)
{
    if(root == NULL)
        return;
    
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(node* root)
{
    if(root == NULL)
        return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";

}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    cout << "In Order Traversal: ";
    inOrderTraversal(root);
    cout<<endl;

    cout << "Pre Order Traversal: ";
    preOrderTraversal(root);
    cout<<endl;

    cout << "Post Order Traversal: ";
    postOrderTraversal(root);
    cout<<endl;
    
    return 0;
}

// Sample Input : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// Sample Output : In Order Traversal: 7 3 11 1 17 5 
//                 Pre Order Traversal: 1 3 7 11 5 17 
//                 Post Order Traversal: 7 11 3 17 5 1 
