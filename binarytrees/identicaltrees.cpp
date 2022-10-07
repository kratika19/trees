// Two trees are identical when they have the same data and the arrangement of data is also the same
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

bool checkIfIdentical(node* root1, node* root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    
    if(root1==NULL && root2!=NULL)
        return false;
    
    if(root2==NULL && root1!=NULL)
        return false;

    bool left = checkIfIdentical(root1->left, root2->left);
    bool right = checkIfIdentical(root1->right, root2->right);
    bool value = root1->data == root2->data;


    if(left && right && value)
        return true;
    else
        return false;
}


int main()
{

    cout<<"Enter values of 1st tree "<<endl;
    node* root1 = NULL;
    root1 = buildTree(root1);

    cout<<"Enter values of 2nd tree "<<endl;
    node* root2 = NULL;
    root2 = buildTree(root2);

    cout<<"Trees are identical : "<<checkIfIdentical(root1, root2)<<endl;
    return 0;
}

