#include <stdio.h>
#include <stdlib.h>
#include "lab06.h"

Node* createTree()
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = -1;
    return temp;
}

Node* createLeaf(int k)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = k;
    temp->left = temp->right = NULL;

    return temp;
}

void insert(Node *tree, int k)
{
    if (k == tree->data)
    return ;

    if (tree->data == -1)
    {
        tree->data = k;
        return ;
    }

    if (k > tree->data)
    {
        if (tree->right)
            insert(tree->right, k);
        else
            tree->right = createLeaf(k);
    }
    else
    {
        if (tree->left)
            insert(tree->left, k);
        else
            tree->left = createLeaf(k);
    }

}

Node* search(Node *tree, int k)
{
    if (tree)
    {
        int current_data = tree->data;
        if(current_data == k)
        {
            return tree;
        }
        else if (k > current_data)
        {
            search(tree->right, k);
        }
        else
        {
            search(tree->left, k);
        }
    }
    else
    {
        return NULL;
    }
}

Node *findMinNode(Node *tree)
{
    if (tree && tree->left)
        return findMinNode(tree->left);
    else
        return tree;
}

Node* removeNode(Node *tree, int k, Node *original_tree)
{
    if (!tree->right && !tree->left && tree->data != k)
    {
        return splay(original_tree, tree->data);
    }

    if (!tree) return NULL;

    if (k < tree->data)
        tree->left = removeNode(tree->left, k, original_tree);
    else if (k > tree->data)
        tree->right = removeNode(tree->right, k, original_tree);
    else
    {
        if (tree->left == NULL)
        {
            Node *temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL)
        {
            Node *temp = tree->left;
            free(tree);
            return temp;
        }

        // Node with two children
        Node *temp = findMinNode(tree->right);

        tree->data = temp->data;

        tree->right = removeNode(tree->right, temp->data, original_tree);
    }
    return tree;

}

Node *findParent(Node *tree, Node *k)
{
    Node *parent = tree;
    int current_data;

    if (parent == k)
        return NULL;

    while(parent && (parent->left != k || parent->right != k))
    {
        current_data = parent->data;
        if (k->data > current_data)
            parent = parent->right;
        else
            parent = parent->left;
    }

    return parent;
}

void inorder(Node *tree)
{
    if(tree)
    {
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
}

void preorder(Node *tree)
{
    if(tree)
    {
        printf("%d ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

Node *rightRotate(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}
 
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}
 
Node *splay(Node *root, int key)
{
    // Base cases: root is NULL or key is present at root
    if (root == NULL || root->data == key)
        return root;
 
    // Key lies in left subtree
    if (root->data > key)
    {
        // Key is not in tree, we are done
        if (root->left == NULL) return root;
 
        // Zig-Zig (Left Left)
        if (root->left->data > key)
        {
            // First recursively bring the key as root of left-left
            root->left->left = splay(root->left->left, key);
 
            // Do first rotation for root, second rotation is done after else
            root = rightRotate(root);
        }
        else if (root->left->data < key) // Zig-Zag (Left Right)
        {
            // First recursively bring the key as root of left-right
            root->left->right = splay(root->left->right, key);
 
            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
 
        // Do second rotation for root
        return (root->left == NULL)? root: rightRotate(root);
    }
    else // Key lies in right subtree
    {
        // Key is not in tree, we are done
        if (root->right == NULL) return root;
 
        // Zag-Zig (Right Left)
        if (root->right->data > key)
        {
            // Bring the key as root of right-left
            root->right->left = splay(root->right->left, key);
 
            // Do first rotation for root->right
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->data < key)// Zag-Zag (Right Right)
        {
            // Bring the key as root of right-right and do first rotation
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
 
        // Do second rotation for root
        return (root->right == NULL)? root: leftRotate(root);
    }
}
 
Node *searchSplay(Node *root, int key)
{
    return splay(root, key);
}