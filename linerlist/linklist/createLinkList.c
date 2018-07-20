#include "general.h"

linkList createLinkList(int nums[], int length)
{
    linkList head, p, r = NULL;

    for(int i = 0; i < length; i++)
    {
        p = (linkList) malloc(sizeof(linkNode));
        p->data = nums[i];
        p->next = NULL;

        if (head == NULL)
            head = p;
        else
            r->next = p;

        r = p;
    }

    return head;
}
