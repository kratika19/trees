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

void buildlevelOrderTraversal(node* &root)
{
    queue<node*> q;
    cout<<"Enter data for root: ";
    int data;
    cin>> data;

    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for "<< temp->data << " : ";
        int leftData;
        cin>>leftData;

        if(leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp -> left);
        }

        cout<<"Enter right node for "<< temp->data << " : ";
        int rightData;
        cin>> rightData;

        if(rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp -> right);
        }       
    }
}

int main()
{
    node* root = NULL;
    buildlevelOrderTraversal(root);
    return 0;
}

