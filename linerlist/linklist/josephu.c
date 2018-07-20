#include "general.h"

/*
 * 根据nums数组建立一个循环链表（无头结点），list指向链表第一个节点
 * 调用者需要释放链表空间。
 * success: return 0
 * failed: return -1
 */
int create(linkList *list, int nums[], int numsSize)
{
    linkList r = NULL, p = NULL;
    *list = NULL;
    if (numsSize <= 0 || nums == NULL)
        return -1;

    for (int i = 0; i < numsSize; i++)
    {
        // new a linkNode
        p = (linkList) malloc (sizeof(linkNode));
        p->data = nums[i];
        p->next = *list;
        // first node and the others.
        if (*list == NULL)
            *list = p;
        else
            r->next = p;
        // next
        r = p;
    }

    return 0;
}

/*
 * 约瑟夫过程
 * 数学推导结果：J_m_(n+1) = (J_m_(n) + m) % (n+1)
 */
int josephu(linkList list, int k, int m)
{
    if (list == NULL)
        return -1;
    linkList p = list;
    //find start node.
    for (int i = 0; i < k-1; i++)
        p = p->next;
    // for each m-node, delete it.
    while(p->next != p)
    {
        linkList r;
        for (int i = 0; i < m-1; i++)
        {
            r = p;
            p = p->next;
        }
        //delete
        printf("%d ", p->data);
        r->next = p->next;
        free(p);
        // 重新开始计数
        p = r->next;
    }
    printf("%d\n", p->data);
    return p->data;
}

int main(void)
{
    int nums[MAXSIZE] = {1,2,3,4,5,6,7,8,9,10};
    int numsSize = 10;
    int k, m;
    linkList list;
    printf("Josephu problem: input number k, m:\n");
    scanf("%d %d", &k, &m);
    int err = create(&list, nums, numsSize);
    if (err == -1)
    {
        printf("Error in Create LinkList.\n");
        return -1;
    }
    josephu(list, k, m);

    //free list.

    return 0;
}
