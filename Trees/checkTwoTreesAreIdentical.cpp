#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *insert(node *root)
{
    cout << "Enter data :" << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new node(data);
    cout << "Enter left value for " << data << " : ";
    root->left = insert(root->left);
    cout << "Enter right value for " << data << " : ";
    root->right = insert(root->right);

    return root;
}
bool isIdentical(node *r1, node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    bool leftAns = isIdentical(r1->left, r2->left);
    bool rightAns = isIdentical(r1->right, r2->right);

    if (leftAns && rightAns && r1->data == r2->data)
        return true;
    return false;
}
int main()
{
    node *root1 = NULL;
    node *root2 = NULL;
    root1 = insert(root1);
    root2 = insert(root2);

    if (isIdentical(root1, root2))
        cout << "Yes!!" << endl;
    else
        cout << "No!!" << endl;
}
// 5 2 3 -1 -1 1 -1 -1 3 6 -1 -1 8 -1 -1