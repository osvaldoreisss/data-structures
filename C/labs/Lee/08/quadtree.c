#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quadtree.h"
#include "list.h"

qtree* qtree_create(int width, int height, int maxDepth, int maxObjectsPerNode)
{
    qtree *created = malloc(sizeof(qtree));

    if (created)
    {
        created->maxDepth = maxDepth;
        created->maxObjectsPerNode = maxObjectsPerNode;
        created->root = qtree_createNode(0, 0, width, height, maxObjectsPerNode, 0);

        return created;
    }

    return NULL;
}

void qtree_destroy(qtree *t)
{
    free(t);
}

void qtree_destroyNodes(qnode *root)
{
    if (root->children[0]) qtree_destroyNodes(root->children[0]);
    if (root->children[1]) qtree_destroyNodes(root->children[1]);
    if (root->children[2]) qtree_destroyNodes(root->children[2]);
    if (root->children[3]) qtree_destroyNodes(root->children[3]);
    free(root);
}

int qtree_getIndex(qnode *n, double x, double y, double w, double h)
{
    int dif0, dif1, dif2, dif3;
    return -1;
}

void qtree_split(qnode *n)
{
    int nw, nh, nLevel, maxObjects, x, y;

    // Getting the parameters for the children
    x = n->x;
    y = n->y;
    nw = n->w / 2;
    nh = n->h / 2;
    nLevel = n->level + 1;
    maxObjects = n->maxObjects;

    // Splitting the space into the four children
    n->children[0] = qtree_createNode(x, y, nw, nh, maxObjects, nLevel);
    n->children[1] = qtree_createNode(x, y + nh, nw, nh, maxObjects, nLevel);
    n->children[2] = qtree_createNode(x + nw, y, nw, nh, maxObjects, nLevel);
    n->children[3] = qtree_createNode(x + nw, y + nh, nw, nh, maxObjects, nLevel);

    // Reinserting the current objects
    node* aux = n->objects->head;
    ball* b;
    while(aux)
    {
        b = aux->b;
        int bx, by;

        bx = b->x;
        by = b->y;
        list_remove(n->objects, b);

        if (bx <= x + nw && by <= y + nh)
        {
            list_insertBack(n->children[0], b);
        }
        else if (bx <= x + nw && by <= y + nh + nh)
        {
            list_insertBack(n->children[1], b);
        }
        else if (bx <= x + nw + nw && by <= y + nh)
        {
            list_insertBack(n->children[2], b);
        }
        else
        {
            list_insertBack(n->children[3], b);
        }
    }
}

qnode* qtree_createNode(int x, int y, int w, int h, int maxObjects, int level)
{
    qnode *created = malloc(sizeof(qnode));

    if (created)
    {
        created->x = x;
        created->y = y;
        created->h = h;
        created->maxObjects = maxObjects;
        created->level = level;

        return created;
    }

    return NULL;
}

void qtree_insert(qtree *tree, qnode *treeNode, ball *b)
{
}

void qtree_retrieve(qnode *root, double x, double y, double w, double h, list *objects)
{
}
