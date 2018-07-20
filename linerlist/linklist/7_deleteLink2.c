#include "general.h"

int deleteLink2(linkList list, linkList q)
{
    if (list == q)
        list = list->next;
    else
    {
        // first, find the precursor node of q.
        linkList r = list;
        while(r != NULL && r->next != q)
            r = r->next;

        if (NULL == r)
            return -1;
        // remove q node
        r->next = q->next;
    }

    free(q);
    return 0;
}
