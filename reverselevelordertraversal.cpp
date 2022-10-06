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

void reverseLevelOrderTraversal(node *root)
{
    queue<node *> q;
    stack<node *> s;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (temp->right)
                q.push(temp->right);
            if (temp->left)
                q.push(temp->left);
        }
    }

    while(!s.empty())
    {
        node* temp = s.top();
        s.pop();
        if(temp!=NULL)
            cout<<temp->data<<" ";
        else
            cout<<endl;
    }
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    cout << "Reverse Level Order Traversal : ";
    reverseLevelOrderTraversal(root);
    cout<<endl;
    return 0;
}

// Sample Input : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// Sample Output : 7 11 17
//                 3 5
//                 1
