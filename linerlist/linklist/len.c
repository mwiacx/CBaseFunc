#include "general.h"
int len(linkList list){
    int length = 0;
    linkList p = list;

    while (p != NULL)
    {
        p = p->next;
        length++;
    }

    return length;
}