/*
 * insert a into the location i of the array
 * if success, return 0; otherwise return -1
 */
#include <stdio.h>
#define MaxSize 100

int
insert(int nums[], int *length, int a, int index)
{
    if ( index < 0 || index >= *length)
        return -1;

    if (MaxSize == *length)
        return -1;

    for (int i = *length-1; i >= index; i--)
    {
        nums[i+1] = nums[i];
    }
    // assgin a to nums[index]
    nums[index] = a;
    // length += 1
    *length += 1;
    
    return 0;
}

int main(void){
    int nums[MaxSize] = {5, 4, 6, 12, -1};
    int length = 5;
    int a = 8;
    int index = 3;

    insert(nums, &length, a, index);

    for (int i = 0; i < length; i++)
    {
        printf("i = %d, num = %d\n", i, nums[i]);
    }

    return 0;
}