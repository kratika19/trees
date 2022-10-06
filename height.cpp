#include <bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter data : "<<endl;
    int data;
    cin>> data;
    
    root = new node(data);
    
    if(data == -1)
        return NULL;
        
    cout<<"Enter left child of "<<data<<endl;
    root->left = buildTree(root->left);
    
    cout<<"Enter right child of "<<data<<endl;
    root->right = buildTree(root->right);
    
    return root;
}

int height(node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right)+ 1;
}

int main()
{
    node* root = NULL;
    root = buildTree(root);

    cout<<endl<<"Height of tree : "<< height(root)<<endl;
    return 0;
}


// Sample Input : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// Sample Output : 3

