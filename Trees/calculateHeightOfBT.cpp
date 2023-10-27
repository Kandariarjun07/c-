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
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *insert(node *root){
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
int height(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    return max(left, right) + 1;
}
int main()
{
    node *root = NULL;
    root = insert(root);
    cout << "Height of tree is : " << height(root);
}
