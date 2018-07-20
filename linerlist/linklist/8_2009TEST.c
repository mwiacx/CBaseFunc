#include "general.h"

linkList search(linkList list, int k)
{
    if (list == NULL || k <= 0)
        return NULL;

    linkList p= list,q = list;

    for(int i = 0; i < k-1; i++)
    {
        p = p->next;
        if (p == NULL)
            return NULL;
    }

    while(p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    return q;
}

int main(void)
{
    int nums[MAXSIZE] = {7, 5, 9, 0, 2, 3};
    int length = 6;
    int k = 4;

    linkList list = createLinkList(nums, length);
    if (NULL == list)
        printf("Error in createLinkList\n");
    linkList q = search(list, k);
    if (NULL == q)
        printf("Error in search\n");

    printf("%d\n", q->data);

    return 0;
}
