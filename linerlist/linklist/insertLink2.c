#include "general.h"
void insertLink2(linkList list, linkList q, int data)
{
    if (q == NULL)
        return;
    // 创建链表
    linkList new = (linkList) malloc(sizeof(linkNode));
    new->data = data;
    new->next = NULL;

    // if  list is NULL
    if (list == NULL)
        list = p;
    else
    {
        p->next = q->next;
        q->next = p;
    }

    return;
}
