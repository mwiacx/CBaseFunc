#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

// linkList
typedef struct node{
    int data;
    struct node *next;
} linkNode, *linkList;
// dlinkList
typedef struct dnode{
    int data;
    struct dnode *rlink, *llink;
}DNode, *DLinkList;

//function
int len(linkList list);
linkList createLinkList(int nums[], int length);
void insertLink2(linkList list, linkList q, int data);
