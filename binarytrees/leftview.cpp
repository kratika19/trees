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

vector<int> leftView(node* root)
{
   map<int, int> m; //lvl, data
   queue<pair<node*, int> >q; //node, lvl

   vector<int> ans;

   if(root == NULL)
    return ans;

    q.push(make_pair(root, 0));

    while(!q.empty())
    {
        pair<node*, int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int lvl = temp.second;

        if(m.count(lvl)==0)
            m[lvl] = frontNode->data;
        
        if(frontNode->left)
            q.push(make_pair(frontNode->left, lvl+1));

        if(frontNode->right)
            q.push(make_pair(frontNode->right, lvl+1));
    }

    for(auto i: m)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    cout << "Boundary Traversal : ";
    vector<int> a = leftView(root);

    for (auto i : a)
        cout << i << " ";
    cout<<endl;

    return 0;
}

// Sample Input : 1 2 4 -1 -1 5 -1 7 -1 -1 3 -1 6 -1 8 -1 9 -1 -1
// Sample Output : 1 2 4 7 9
