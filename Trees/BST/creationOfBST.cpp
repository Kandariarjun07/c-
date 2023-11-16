#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void insertToBST(node *&root, int val)
{
    if (val == -1)
    {
        return;
    }
    node *temp = new node(val);
    if (root == NULL)
    {
        root = temp;
    }
    else if (val > root->data)
    {
        insertToBST(root->right, val);
    }
    else if (val < root->data)
    {
        insertToBST(root->left, val);
    }
}
void levelOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

// 50 40 60 20 30 55 65 5 10 25 35 -1

int main()
{
    node *root = NULL;
    cout << "Enter data : ";
    int val;
    cin >> val;
    insertToBST(root, val);
    while (val != -1)
    {
        cin >> val;
        insertToBST(root, val);
    }
    levelOrderTraversal(root);
    return 0;
}