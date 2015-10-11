#include <stdio.h>
#include <stdlib.h>
#include "splay.h"

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
    printf("Searching for %d\n", k);
    Node *temp = tree;
    if (tree)
    {
        int current_data = temp->data;
        printf("Search for %d at %d\n", k, current_data);
        if(current_data == k)
        {
            printf("Found!\n");
            return temp;
        }
        else if (k > current_data)
        {
            search(temp->right, k);
        }
        else
        {
            search(temp->left, k);
        }
    }
    return NULL;
}

void removeNode(Node *tree, int k)
{
    if(tree)
    {
        Node *target = search(tree, k);
        Node *parent = findParent(tree, target);
        printf("Target and parent found.");
        if(target)
        {
            // If target has no siblings, just kill it.
            if (!target->left && !target->right)
            {
                if(parent && parent->left == target)
                {
                    parent->left = NULL;
                }
                else if(parent)
                {
                    parent->right = NULL;
                }
                free(target);
            }
            // If target has one sibling
            else if (target->left || target->right)
            {
                int sibling;
                if (target->left)
                {
                    sibling = target->left->data;
                }
                else
                {
                    sibling = target->right->data;
                }
                target->data = sibling;
            }

            //If target has BOTH siblings
            else if (target->left && target->right)
            {
                target->data = target->right->data;
                free(target->right);
                target->right = NULL;
            }
        }
    }
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

