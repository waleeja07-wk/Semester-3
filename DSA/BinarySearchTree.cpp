#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// ---------- Traversals ----------

class BST
{
private:
    Node *root;

    void insert(Node *&root, int val)
    {
        if (!root)
        {
            root = new Node(val);
            return;
        }

        if (root->data == val)
        {
            return;
        }
        if (val < root->data)
        {
            insert(root->left, val);
        }
        else if (val > root->data)
        {
            insert(root->right, val);
        }
    }

    void remove(Node *&root, int val)
    {
        if (root == nullptr)
            return;
        if (val < root->data)
            remove(root->left, val);
        if (val > root->data)
            remove(root->right, val);
        else
        {
            Node *t = root;
            if (root->left)
            {
                root = root->left;
            }
            else if (root->right)
            {
                root = root->right;
            }
            else // two children
            {
                Node *succ = root->right;     // inorder successor =
                while (succ->left != nullptr) // smallest node in right subtree
                    succ = succ->left;

                root->data = succ->data;         // copy its value here
                remove(root->right, succ->data); // delete the successor node
            }
            delete t;
        }
    }

    void inorder(Node *root)
    {
        if (!root)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (!root)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if (!root)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void levelOrder(Node *root)
    {
        if (!root)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *cur = q.front();
            q.pop();
            cout << cur->data << " ";
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }

    // ---------- Common functions ----------
    int height(Node *root)
    { // height in nodes
        if (!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int countNodes(Node *root)
    {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int countLeaves(Node *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        return countLeaves(root->left) + countLeaves(root->right);
    }

    int sumNodes(Node *root)
    {
        if (!root)
            return 0;
        return root->data + sumNodes(root->left) + sumNodes(root->right);
    }

    void mirror(Node *root)
    { // swap left and right everywhere
        if (!root)
            return;
        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
    }

    bool isSame(Node *a, Node *b)
    {
        if (!a && !b)
            return true;
        if (!a || !b)
            return false;
        return a->data == b->data && isSame(a->left, b->left) && isSame(a->right, b->right);
    }

    bool isBalanced(Node *root)
    {
        if (!root)
            return true;
        int diff = abs(height(root->left) - height(root->right));
        return diff <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

public:
    void insert(int val)
    {
        insert(root, val);
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inorder(root);
    cout << endl; // 4 2 5 1 3
    preorder(root);
    cout << endl; // 1 2 4 5 3
    postorder(root);
    cout << endl; // 4 5 2 3 1
    levelOrder(root);
    cout << endl; // 1 2 3 4 5
    cout << "Height: " << height(root) << endl;
    cout << "Total Nodes: " << countNodes(root) << endl;
}