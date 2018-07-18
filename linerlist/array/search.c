/*
 *
 */
#include <stdio.h>
#define MaxSize 100

// return the index of the first a found in array nums
int
search(int nums[], int length, int a)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (a == nums[i])
            return i;
    }
    // not find
    return -1;
}

int main(void){
    int nums[MaxSize] = {5, 4, 6, 12, -1};
    int length = 5;
    int a = 6;

    int index = search(nums, length, a);

    printf("a = %d, index = %d\n", a, index);

    return 0;
}