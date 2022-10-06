// Given a binary tree, find if it is height balanced or not. A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 


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

pair<bool,int> isBalancedFast(node* root)
{
    if(root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    ans.second = max(left.second, right.second) + 1;

    if(leftAns && rightAns && diff)
        ans.first = true;
    
    else
        ans.first = false;

    return ans;
}

bool isBalanced(node* root)
{
    return isBalancedFast(root).first;
}

int main()
{
    node* root = NULL;
    root = buildTree(root);

    cout<<endl<<"Is Tree Balanced : "<< isBalanced(root)<<endl;
    return 0;
}


// Sample Input : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// Sample Output : 1

