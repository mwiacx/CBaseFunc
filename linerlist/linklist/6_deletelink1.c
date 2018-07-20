#include "general.h"

int deleteLink1(linkList list, linkList r, linkList q)
{
    if (NULL == list | NULL == r | NULL == q)
        return -1;

    if (list == q)
        list = q->next;
    else
        r->next = q->next;

    free(q);
    return 0;
}
