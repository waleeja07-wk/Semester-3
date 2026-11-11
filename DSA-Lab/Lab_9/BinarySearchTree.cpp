#include <iostream>
#include "TreePrinter.hpp"

using namespace std;

class BinarySearchTree
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node *root;

    Node *clear(Node *tree);
    void preOrderTraversal(Node *tree);
    void inOrderTraversal(Node *tree);
    void postOrderTraversal(Node *tree);

public:
    BinarySearchTree() { root = nullptr; }
    ~BinarySearchTree() { root = clear(root); }
    void clear() { root = clear(root); }
    void preOrderTraversal() { preOrderTraversal(root); }
    void inOrderTraversal() { inOrderTraversal(root); }
    void postOrderTraversal() { postOrderTraversal(root); }
    void display() { TreePrinter<Node>::print(root); }
    void createTree()
    {
        root = new Node(50);
        root->left = new Node(30);
    }
};

int main()
{
    BinarySearchTree tree;

    tree.display();
}

BinarySearchTree::Node *BinarySearchTree::clear(Node *tree)
{
    if (tree == nullptr)
    {
        return tree;
    }

    clear(tree->left);
    clear(tree->right);

    delete tree;
    tree = nullptr;
    return tree;
}

void BinarySearchTree::preOrderTraversal(Node *tree)
{
    if (tree == nullptr)
    {
        return;
    }

    cout << tree->data << " ";
    preOrderTraversal(tree->left);
    preOrderTraversal(tree->right);
}

void BinarySearchTree::inOrderTraversal(Node *tree)
{
    if (tree == nullptr)
    {
        return;
    }

    inOrderTraversal(tree->left);
    cout << tree->data << " ";
    inOrderTraversal(tree->right);
}

void BinarySearchTree::postOrderTraversal(Node *tree)
{
    if (tree == nullptr)
    {
        return;
    }

    postOrderTraversal(tree->left);
    postOrderTraversal(tree->right);
    cout << tree->data << " ";
}
