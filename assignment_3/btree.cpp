// A program to demonstrate Binary Tree
/*
Binary tree is a tree in which every node has at most two child nodes.

So a typical binary tree will have the following components:

    A left subtree
    A root node
    A right subtree
*/

#include <iostream>

struct bintree_node
{
    struct bintree_node *left;
    int data;
    struct bintree_node *right;
};

// create a new node with given data value and return the address of the new node
struct bintree_node *getnode(int data)
{
    struct bintree_node *temp = new bintree_node;

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Bst
{
private:
    // member to store root node's address
    struct bintree_node *root;

    // member functions
public:
    Bst()
    {
        this->root = NULL;
    }
    int isEmpty()
    {
        return (root == NULL);
    }
    void insert(int data);
    void preorder_display();
    void preorder(bintree_node *ptr);
    void inorder_display();
    void inorder(bintree_node *ptr);
    void postorder_display();
    void postorder(bintree_node *ptr);
};

void Bst::insert(int data)
{
    // if the current data is less than current node then traverse left and vice versa and then store at the leaf position
    struct bintree_node *temp = getnode(data);
    struct bintree_node *ptr = NULL;
    struct bintree_node *parent = NULL;

    // if root is empty then assign the new node to root
    if (isEmpty())
    {
        this->root = temp;
        return;
    }
    // traverse to the appropriate position
    ptr = root;
    while (ptr != NULL)
    {
        // to store the parent node of the current node
        parent = ptr;
        if (data >= ptr->data)
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }
    // got the location of the node now  check to insert it at leeft or right
    if (data >= parent->data)
        parent->right = temp;
    else
        parent->left = temp;
}

void Bst::inorder_display()
{
    std::cout << "\n---------------------------------------" << std::endl;
    inorder(root);
    std::cout << "\n---------------------------------------" << std::endl;
}

void Bst::inorder(struct bintree_node *ptr)
{
    inorder(ptr->left);
    std::cout << ptr->data << " ";
    inorder(ptr->right);
}

int main()
{
    return 0;
}