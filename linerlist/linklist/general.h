#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct node{
    int data;
    struct node *next;
} linkNode, *linkList;

//function
int len(linkList list);
linkList createLinkList(int nums[], int length);