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

vector<int> zigZagTraversal(node* root)
{
    vector<int> result;

    if(root == NULL)
        return result;

    queue<node*> q;
    q.push(root);

    bool leftToRight = true;
    
    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for(int i=0;i<size;i++)
        {
            node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if(frontNode->left)
                q.push(frontNode->left);

            if(frontNode->right)
                q.push(frontNode->right);

        }


        leftToRight = !leftToRight;
        for(auto i : ans)
            result.push_back(i);
    }
    return result;
}

int main()
{
    node* root = NULL;
    root = buildTree(root);

    cout<<"ZigZag Traversal : ";    
    vector<int> a = zigZagTraversal(root);

    for(auto i:a)
        cout<<i<<" ";
    return 0;
}


// Sample Input : 1 2 3 -1 -1 5 -1 -1 4 -1 6 7 -1 -1 8 -1 -1
// Sample Output : 1 4 2 3 5 6 8 7 

