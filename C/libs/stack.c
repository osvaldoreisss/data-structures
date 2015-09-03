/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  Implementation of a stack using linked lists
 *
 *        Version:  1.0
 *        Created:  03-09-2015 10:02:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Felipe Rodrigues (FBidu)
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
    int data;
    struct _node *next;
} Node;


