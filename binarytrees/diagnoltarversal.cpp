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

// vector<int> diagonalTraversal(node *root)
// {
//     vector<int> result;
//     queue<pair<node*, int> >q;
//     map<int, vector<int> > nodes;

//     if(root == NULL)
//         return result;

//     q.push(make_pair(root, 0));

//     while(!q.empty())
//     {
//         pair<node*, int> temp = q.front();
//         q.pop();

//         node* frontNode = temp.first;
//         int hd = temp.second;

//         nodes[hd].push_back(frontNode->data);

//         if(frontNode->left)    
//             q.push(make_pair(frontNode->left, hd+1));

//         if(frontNode->right)    
//             q.push(make_pair(frontNode->right, hd));
//     }

//     for(auto i: nodes)
//     {
//         for(auto j: i.second)
//             result.push_back(j);
//     }

//     return result;
// }


vector<int> diagonalTraversal(node *root)
{
    vector<int> result;
    queue<node*> q;

    if(root == NULL)
    return result;

    q.push(root);

    while(!q.empty())
    {
        node* frontNode = q.front();
        q.pop();

        while (frontNode!=NULL)
        {
            result.push_back(frontNode->data);

            if(frontNode->left)
                q.push(frontNode->left);
            
            frontNode = frontNode->right;
        }
        
    }
    
    return result;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    cout << "Diagonal Traversal : ";
    vector<int> a = diagonalTraversal(root);

    for (auto i : a)
        cout << i << " ";
    return 0;
}

// Sample Input : 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
// Sample Output : 8 10 14 3 6 7 13 14
