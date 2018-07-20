#include "general.h"

/*
 * 在list链表的第i个节点后插入一个新节点，数据为data
 * Success: return 0
 * Failed: return -1
 */
int insertLink3(linkList list, int i, int data)
{
    // find the i'th node
    linkList p = list;
    for (int j = 0; j < i-1; j++)
    {
        p = p->next;
        if (NULL == p)
            return -1;
    }

    linkList q = (linkList) malloc(sizeof(linkNode));
    q->data = data;

    q->next = p->next;
    p->next = q;

    return 0;
}
