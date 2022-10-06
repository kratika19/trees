// The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. 

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

pair<int, int> FastDiameter(node *root)
{
    if(root == NULL)
    {
        // first -> diameter , second -> height
        pair<int, int> p= make_pair(0,0);
        return p;
    }

    pair<int,int> left = FastDiameter(root->left);
    pair<int,int> right = FastDiameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(node* root)
{
    return FastDiameter(root).first;
}

int main()
{
    node* root = NULL;
    root = buildTree(root);

    cout<<endl<<"Diameter of tree : "<< diameter(root)<<endl;
    return 0;
}


// Sample Input : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// Sample Output : 3
// T(C) = O(n)
// S(C) = O(height)

