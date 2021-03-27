#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct ds_tree
{
    TREE_NODE_T pRoot;
} TREE;

typedef struct ds_treenode
{
    struct ds_treenode leftChild;
    struct ds_treenode rightChild;
    char word[64];
} TREE_NODE_T;

int main()
{
    
}
