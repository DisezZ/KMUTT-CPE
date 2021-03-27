/* 
 *  TryThis 6
 *  Simple sorted binary tree - version 2
 *
 *  Used to test student's understanding of keeping data during
 *  traversal
 *  Created by Sally Goldin, 14 Feb 2020
 *
 * Name: Lutfee Deemae   ID: 63070503448
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    char nodekey[64];         /* string identifying the node */
    struct _node *leftChild;  /* ptr to left child if any */
    struct _node *rightChild; /* ptr to right child if any */
} NODE_T;

/* Recursive function to insert a node into 
 * the tree using the smaller-left, larger-right rule.
 * Assumes that the passed current node is not NULL.
 * Also assumes no two 'nodekey' values will be equal.
 * Arguments:
 *    currentNode -  Current location in the tree
 *    newNode     -  New node to insert
 */
void insertNode(NODE_T *currentNode, NODE_T *newNode)
{
    if (strcmp(newNode->nodekey, currentNode->nodekey) < 0)
    {
        if (currentNode->leftChild == NULL)
        {
            currentNode->leftChild = newNode;
            printf("Adding '%s' as left child of '%s'\n",
                   newNode->nodekey, currentNode->nodekey);
        }
        else
            insertNode(currentNode->leftChild, newNode);
    }
    else /* go right */
    {
        if (currentNode->rightChild == NULL)
        {
            currentNode->rightChild = newNode;
            printf("Adding '%s' as right child of '%s'\n",
                   newNode->nodekey, currentNode->nodekey);
        }
        else
            insertNode(currentNode->rightChild, newNode);
    }
}

/* Create and insert a new node
 * Allocates memory, copies the key value and either sets
 * the root, or calls the recursive insertion function.
 * Arguments:
 *    keystring     -   Value to store in the node
 *    pRoot         -   Pointer to the root (which is already a ptr)
 *                      Must be NODE_T** because first call will 
 *                      modify its value.
 */
void createNewNode(char *keystring, NODE_T **pRoot)
{
    NODE_T *new = calloc(1, sizeof(NODE_T));
    if (new == NULL)
    {
        printf("Memory allocation failed - exiting\n");
        exit(1);
    }
    /* copy in the key value */
    strcpy(new->nodekey, keystring);
    if (*pRoot == NULL) /* first node in tree */
    {
        printf("Adding '%s' as root node\n", keystring);
        *pRoot = new;
    }
    else
    {
        insertNode(*pRoot, new);
    }
}

/* Recursive function to do an in-order traversal,
 * printing the key value at each node.
 * Argument:
 *    currentNode  -  Current node we're visiting.
 */
void traverseInOrder(NODE_T *currentNode)
{
    if (currentNode->leftChild != NULL)
        traverseInOrder(currentNode->leftChild);
    printf("Node key: %s\n", currentNode->nodekey);
    if (currentNode->rightChild != NULL)
        traverseInOrder(currentNode->rightChild);
}

/* Recursive function to traverse the tree, counting how
 * many of the strings in the tree start with a 
 * specified character.
 * Arguments
 *    currentNode     Pointer to current tree node
 *    searchChar      Character we are counting
 *    pCount          Output argument for accumulating the count
 */
void countInitialChars(NODE_T *currentNode, char searchChar, int *pCount)
{
    /** WRITE YOUR CODE HERE */
    if (searchChar == currentNode->nodekey[0])
    {
        ++(*pCount);
    }
    if (currentNode->leftChild != NULL)
    {
        countInitialChars(currentNode->leftChild, searchChar, pCount);
    }
    if (currentNode->rightChild != NULL)
    {
        countInitialChars(currentNode->rightChild, searchChar, pCount);
    }
}

/* Main function builds a sample tree then tries to traverse it */
int main()
{
    NODE_T *root = NULL; /* tree starts out empty */
    char input[32];      /* for terminal input */
    int bDone = 0;       /* to control the loop */

    createNewNode("giraffe", &root);
    createNewNode("ant", &root);
    createNewNode("tiger", &root);
    createNewNode("lion", &root);
    createNewNode("elephant", &root);
    createNewNode("buffalo", &root);
    createNewNode("goat", &root);
    createNewNode("zebra", &root);
    createNewNode("cow", &root);
    createNewNode("gorilla", &root);

    printf("\nAbout to traverse in-order\n");
    traverseInOrder(root);

    while (!bDone)
    {
        char letter = 0;
        int count = 0;
        printf("Count strings starting with what letter? ");
        fgets(input, sizeof(input), stdin);
        if (strncasecmp(input, "DONE", 4) == 0)
            bDone = 1;
        else
        {
            sscanf(input, "%c", &letter);
            countInitialChars(root, letter, &count);
            printf("Found %d strings starting with '%c'\n\n", count, letter);
        }
    }
    printf("\nGoodbye!\n");
}