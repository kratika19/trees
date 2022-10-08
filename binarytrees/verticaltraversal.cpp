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

vector<int> verticalTraversal(node* root)
{
    map<int, map<int, vector<int> > > nodes;
    queue<pair<node*, pair<int, int> > > q;
    vector<int> ans;

    if(root == NULL)
        return ans;
    
    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty())
    {
        pair< node*, pair<int, int> > temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        
        if(frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
    }

    for(auto i : nodes)
    {
        for(auto j : i.second)
        {
            for(auto k: j.second)
                ans.push_back(k);
        }
    }
    return ans;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    cout << "Boundary Traversal : ";
    vector<int> a = verticalTraversal(root);

    for (auto i : a)
        cout << i << " ";
    return 0;
}

// Sample Input : 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
// Sample Output : 4 2 1 5 6 3 8 7 9
