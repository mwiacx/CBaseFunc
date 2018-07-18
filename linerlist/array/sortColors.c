/*
 * 荷兰国旗问题(sort Colors)
 * LeetCode: https://leetcode.com/problems/sort-colors/description/
 * 三种方法：
 * 
 */
#include <stdio.h>
#define MAXSIZE 100

/*
 * first method
 * 考虑将数组分成3个部分，start记录红色的队尾，end记录蓝色的队头
 * 中间部分自然为白色
 * 每次遍历：
 * 1. 如果是红色，将其插入首部，并将该位置改为白色。
 * 2. 如果是白色，不变。
 * 3. 如果是蓝色，将其插入队尾，重新遍历该位置（因为交换回来的数字没有被遍历过）。
 */

int sortColors_1(int colors[], int length)
{
    int start = -1, end = length;

    if (length <= 0)
        return -1;
    
    for (int i = 0; i < end; i++)
    {
        if (0 == colors[i])
        {
            colors[i] = 1;
            colors[++start] = 0; // 对于i的赋值一定要在++start之前(考虑i == ++start的情况)。
        }
        else if (1 == colors[i])
            continue;
        else if (2 == colors[i])
        {
            colors[i] = colors[--end];
            colors[end] = 2;
            i--;
        }
        else
            printf("Unkown color %d in array colors.\n", colors[i]);
    }

    return 0;
}
/*
 * Second method.
 * 用3个下标分别记录已排序部分各个颜色的#队尾#。
 * 在遍历过程中：
 * 1. 是红色，意味着白色和蓝色整体后移，长度不变（O(1)），红色长度加1
 * 2. 是白色，意味着蓝色整体后移，长度不变，白色长度加1，红色不变
 * 3. 是蓝色，意味着蓝色长度加1，白色，红色不变。
 */
int sortColors(int colors[], int length)
{
    int red=-1, white=-1, blue=-1;

    if (length <= 0)
        return -1;

    for (int i = 0; i < length; i++)
    {
        if (0 == colors[i]) // red -> 蓝色，白色整体后移
        {
            colors[++blue] = 2;
            colors[++white] = 1;
            colors[++red] = 0;
        }
        else if (1 == colors[i]) // white -> 蓝色整体后移
        {
            colors[++blue] = 2;
            colors[++white] = 1;
        }
        else if (2 == colors[i]) // blue
            colors[++blue] = 2;
        else
            printf("Unkown color %d in array colors!\n", colors[i]);
    }

    return 0;
}

int main(void){
    int colors[MAXSIZE] = {2,0,2,1,1,0};
    int length = 6;
    int success = -1;

    success = sortColors(colors, length);

    if (-1 == success)
        printf("Unkown error in function sortColors\n");

    for (int i = 0; i < length; i++)
    {
        printf("%d ", colors[i]);
    }
    printf("\n");

    return 0;
}